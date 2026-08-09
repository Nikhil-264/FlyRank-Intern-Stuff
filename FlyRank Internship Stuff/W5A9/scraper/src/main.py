import os
import re
import csv
import time
import json
import random
import hashlib
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from datetime import datetime, timezone
from pydantic import BaseModel, Field, HttpUrl, ValidationError
from typing import Optional, List, Dict, Any

# Config: Honest user-agent and timeout (polite scraping settings)
USER_AGENT = "FlyRankInternship-A9/1.0 (+https://github.com/Nikhil-264/FlyRank-Intern-Stuff)"
TIMEOUT = 10
DELAY = 0.5  # 500ms delay between real requests

# Global metrics tracker
stats = {
    "pages_fetched": 0,
    "cache_hits": 0,
    "failed_pages": 0
}

# Define Pydantic Schema for a finished book record
class BookRecord(BaseModel):
    title: str = Field(min_length=1)
    product_url: HttpUrl
    price_text: str
    price_gbp: float = Field(gt=0.0)
    availability_text: str
    rating_text: str = Field(pattern="^(One|Two|Three|Four|Five)$")
    description: Optional[str] = None
    source_page: HttpUrl
    fetched_at: datetime

def log_structured(level: str, message: str, extra: Dict[str, Any] = None):
    """Write structured logs in JSON-Lines format to output/scraper.log (Extra 4)."""
    os.makedirs("output", exist_ok=True)
    log_entry = {
        "timestamp": datetime.now(timezone.utc).isoformat(),
        "level": level,
        "message": message
    }
    if extra:
        log_entry.update(extra)
        
    print(f"[{level}] {message} {json.dumps(extra) if extra else ''}")
    with open("output/scraper.log", "a", encoding="utf-8") as f:
        f.write(json.dumps(log_entry) + "\n")

def clean_filename(url: str) -> str:
    """Convert a URL to a safe filename for local caching."""
    clean = re.sub(r'https?://(www\.)?', '', url)
    clean = re.sub(r'[^a-zA-Z0-9_\-]', '_', clean)
    return f"{clean}.html"

def fetch_with_cache(url: str, cache_path: str) -> str:
    """Fetch HTML from cache or server politely, implementing exponential backoff (Extra 4)."""
    # Ensure cache folder exists
    os.makedirs(os.path.dirname(cache_path), exist_ok=True)
    
    # Check if we have a cached copy
    if os.path.exists(cache_path):
        stats["cache_hits"] += 1
        log_structured("INFO", f"CACHE HIT: {url}", {"url": url, "cache_path": cache_path})
        with open(cache_path, "r", encoding="utf-8") as f:
            return f.read()
            
    # Pro Retry Loop with Exponential Backoff and Retry-After parsing
    headers = {"User-Agent": USER_AGENT}
    max_attempts = 3
    base_delay = 1.0  # start with 1 second delay
    
    for attempt in range(1, max_attempts + 1):
        # Polite delay before hitting the server (cache misses only)
        time.sleep(DELAY)
        
        try:
            log_structured("INFO", f"FETCH: {url}", {"url": url, "attempt": attempt, "max_attempts": max_attempts})
            response = requests.get(url, headers=headers, timeout=TIMEOUT)
            
            # Status check
            if response.status_code == 200:
                stats["pages_fetched"] += 1
                html_content = response.text
                
                # Save to cache
                with open(cache_path, "w", encoding="utf-8") as f:
                    f.write(html_content)
                log_structured("INFO", f"SUCCESS: Cached page {url}", {"url": url, "size_bytes": len(html_content)})
                return html_content
            
            # Rate limiting / Server Error Handling
            elif response.status_code == 429 or 500 <= response.status_code < 600:
                level = "WARNING" if attempt < max_attempts else "ERROR"
                log_structured(level, f"HTTP ERROR {response.status_code} on {url}", {"url": url, "status_code": response.status_code})
                
                if attempt < max_attempts:
                    # Check for Retry-After header
                    retry_after = response.headers.get("Retry-After")
                    if retry_after:
                        try:
                            sleep_dur = float(retry_after)
                            log_structured("INFO", f"Respecting Retry-After header: sleeping for {sleep_dur}s", {"url": url})
                        except ValueError:
                            # if it's a HTTP-date string (we support basic float parsing here, fallback to backoff)
                            sleep_dur = base_delay * (2 ** (attempt - 1)) + random.uniform(0, 0.5)
                    else:
                        # Exponential backoff with jitter
                        sleep_dur = base_delay * (2 ** (attempt - 1)) + random.uniform(0, 0.5)
                        log_structured("INFO", f"Exponential backoff retry in {sleep_dur:.2f}s", {"url": url, "delay": sleep_dur})
                        
                    time.sleep(sleep_dur)
                    continue
            
            # Permanent client errors (404/403) are skipped immediately
            else:
                log_structured("ERROR", f"CLIENT ERROR {response.status_code} on {url}. Skipping (no retry).", {"url": url, "status_code": response.status_code})
                break
                
        except (requests.Timeout, requests.RequestException) as e:
            level = "WARNING" if attempt < max_attempts else "ERROR"
            log_structured(level, f"NETWORK ERROR ({type(e).__name__}) on {url}", {"url": url, "error": str(e)})
            
            if attempt < max_attempts:
                sleep_dur = base_delay * (2 ** (attempt - 1)) + random.uniform(0, 0.5)
                log_structured("INFO", f"Exponential backoff retry in {sleep_dur:.2f}s", {"url": url, "delay": sleep_dur})
                time.sleep(sleep_dur)
                continue
                
    # If all attempts fail
    stats["failed_pages"] += 1
    raise RuntimeError(f"Failed to fetch page {url} after {max_attempts} attempts.")

def discover_book_urls(start_url: str) -> list:
    """Dynamically traverse catalogue pages 1 to 3 and collect book URLs."""
    current_url = start_url
    page_num = 1
    discovered_books = []
    
    while current_url and page_num <= 3:
        cache_path = f"cache/catalogue-page-{page_num}.html"
        html_content = fetch_with_cache(current_url, cache_path)
        soup = BeautifulSoup(html_content, "html.parser")
        
        articles = soup.find_all("article", class_="product_pod")
        for article in articles:
            link_el = article.find("h3").find("a")
            relative_url = link_el.get("href")
            absolute_url = urljoin(current_url, relative_url)
            discovered_books.append({
                "url": absolute_url,
                "source_page": current_url
            })
            
        next_button = soup.find("li", class_="next")
        if next_button:
            next_relative_url = next_button.find("a").get("href")
            current_url = urljoin(current_url, next_relative_url)
            page_num += 1
        else:
            current_url = None
            
    # Remove duplicate links while preserving order
    unique_books = []
    seen = set()
    for book in discovered_books:
        if book["url"] not in seen:
            seen.add(book["url"])
            unique_books.append(book)
            
    return unique_books

def extract_raw_book_details(html_content: str, url: str, source_page: str, fetched_at: str) -> dict:
    """Parse book details page HTML and extract raw text fields (targeted selectors)."""
    soup = BeautifulSoup(html_content, "html.parser")
    
    # Aim selectors specifically at the product_main container
    product_main = soup.find("div", class_="product_main")
    if not product_main:
        raise ValueError("Invalid product detail page structure: missing product_main container")
        
    title = product_main.find("h1").text.strip()
    
    price_el = product_main.find("p", class_="price_color")
    price_text = price_el.text.strip() if price_el else ""
    
    availability_el = product_main.find("p", class_="instock availability")
    availability_text = availability_el.text.strip() if availability_el else ""
    
    # Extract rating word class (e.g. "star-rating Three" -> "Three")
    rating_el = product_main.find("p", class_=re.compile("star-rating"))
    rating_text = ""
    if rating_el:
        classes = rating_el.get("class", [])
        for c in classes:
            if c != "star-rating":
                rating_text = c
                break
                
    # Handle optional description (store None if missing)
    description_header = soup.find("div", id="product_description")
    description = None
    if description_header:
        desc_p = description_header.find_next_sibling("p")
        if desc_p:
            description = desc_p.text.strip()
            
    # Include provenance metadata
    return {
        "title": title,
        "product_url": url,
        "price_text": price_text,
        "availability_text": availability_text,
        "rating_text": rating_text,
        "description": description,
        "source_page": source_page,
        "fetched_at": fetched_at
    }

def normalize_price(price_text: str) -> float:
    """Extract digits and decimals from the price text (e.g., '£51.77' -> 51.77)."""
    match = re.search(r'[\d.]+', price_text)
    if match:
        return float(match.group())
    raise ValueError(f"Could not extract numeric price from '{price_text}'")

def compute_record_hash(record: dict) -> str:
    """Compute a SHA256 hash of core content fields to detect changes."""
    # Exclude dynamic/metadata fields like fetched_at or source_page
    content_str = "|".join([
        str(record.get("title", "")),
        str(record.get("price_gbp", 0.0)),
        str(record.get("availability_text", "")),
        str(record.get("rating_text", "")),
        str(record.get("description", ""))
    ])
    return hashlib.sha256(content_str.encode("utf-8")).hexdigest()

def detect_changes(new_books: List[dict], old_books_path: str) -> Dict[str, int]:
    """Detect changes between this run and the previous run using hashes (Extra 2)."""
    changes = {"new": 0, "changed": 0, "unchanged": 0, "gone": 0}
    
    if not os.path.exists(old_books_path):
        changes["new"] = len(new_books)
        return changes
        
    try:
        with open(old_books_path, "r", encoding="utf-8") as f:
            old_books = json.load(f)
    except Exception:
        changes["new"] = len(new_books)
        return changes

    # Create a mapping of product_url -> hash for old records
    old_map = {}
    for b in old_books:
        url = b.get("product_url")
        if url:
            old_map[url] = compute_record_hash(b)
            
    # Track which old URLs were seen in the new run
    seen_urls = set()
    
    for new_b in new_books:
        url = new_b.get("product_url")
        if not url:
            continue
        new_hash = compute_record_hash(new_b)
        seen_urls.add(url)
        
        if url not in old_map:
            changes["new"] += 1
        elif old_map[url] != new_hash:
            changes["changed"] += 1
        else:
            changes["unchanged"] += 1
            
    # Count books that were present in old run but missing now
    for url in old_map:
        if url not in seen_urls:
            changes["gone"] += 1
            
    return changes

def export_to_csv(books_data: List[dict], csv_path: str):
    """Export validated JSON records into a formatted CSV file (Extra 1)."""
    if not books_data:
        return
        
    fieldnames = [
        "title", "product_url", "price_text", "price_gbp", 
        "availability_text", "rating_text", "description", 
        "source_page", "fetched_at"
    ]
    
    with open(csv_path, "w", newline="", encoding="utf-8") as f:
        writer = csv.DictWriter(f, fieldnames=fieldnames)
        writer.writeheader()
        for record in books_data:
            # Pydantic serialization maps are already flattened strings, simple export
            writer.writerow({k: record.get(k) for k in fieldnames})

def generate_dashboard(report: dict, changes: dict, books_data: List[dict], errors_data: List[dict], html_path: str):
    """Generate a premium dark-themed HTML Dashboard for observability (Extra 3)."""
    # Calculate price metrics
    prices = [b["price_gbp"] for b in books_data if "price_gbp" in b]
    min_price = min(prices) if prices else 0.0
    max_price = max(prices) if prices else 0.0
    avg_price = sum(prices) / len(prices) if prices else 0.0
    
    html_content = f"""<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Polite Scraper Dashboard</title>
    <link href="https://fonts.googleapis.com/css2?family=Outfit:wght@300;400;600;700&display=swap" rel="stylesheet">
    <style>
        :root {{
            --bg-color: #0f172a;
            --card-bg: rgba(30, 41, 59, 0.7);
            --border-color: rgba(255, 255, 255, 0.08);
            --accent-green: #10b981;
            --accent-blue: #3b82f6;
            --accent-red: #ef4444;
            --accent-purple: #8b5cf6;
            --text-main: #f8fafc;
            --text-muted: #94a3b8;
        }}
        * {{
            box-sizing: border-box;
            margin: 0;
            padding: 0;
        }}
        body {{
            background-color: var(--bg-color);
            color: var(--text-main);
            font-family: 'Outfit', sans-serif;
            padding: 2rem;
            min-height: 100vh;
        }}
        .container {{
            max-width: 1200px;
            margin: 0 auto;
        }}
        header {{
            display: flex;
            justify-content: space-between;
            align-items: center;
            margin-bottom: 2.5rem;
            border-bottom: 1px solid var(--border-color);
            padding-bottom: 1.5rem;
        }}
        h1 {{
            font-size: 2.2rem;
            font-weight: 700;
            background: linear-gradient(135deg, #60a5fa, #34d399);
            -webkit-background-clip: text;
            -webkit-text-fill-color: transparent;
        }}
        .timestamp {{
            font-size: 0.9rem;
            color: var(--text-muted);
            background: rgba(255,255,255,0.03);
            padding: 0.5rem 1rem;
            border-radius: 8px;
            border: 1px solid var(--border-color);
        }}
        .grid {{
            display: grid;
            grid-template-columns: repeat(auto-fit, minmax(280px, 1fr));
            gap: 1.5rem;
            margin-bottom: 2.5rem;
        }}
        .card {{
            background: var(--card-bg);
            border: 1px solid var(--border-color);
            border-radius: 16px;
            padding: 1.5rem;
            backdrop-filter: blur(12px);
            box-shadow: 0 4px 30px rgba(0, 0, 0, 0.2);
            transition: transform 0.2s, border-color 0.2s;
        }}
        .card:hover {{
            transform: translateY(-4px);
            border-color: rgba(255, 255, 255, 0.15);
        }}
        .card-title {{
            font-size: 0.9rem;
            text-transform: uppercase;
            letter-spacing: 1px;
            color: var(--text-muted);
            margin-bottom: 0.75rem;
        }}
        .card-value {{
            font-size: 2rem;
            font-weight: 700;
        }}
        .text-green {{ color: var(--accent-green); }}
        .text-blue {{ color: var(--accent-blue); }}
        .text-red {{ color: var(--accent-red); }}
        .text-purple {{ color: var(--accent-purple); }}
        
        .section-title {{
            font-size: 1.4rem;
            margin-bottom: 1.25rem;
            font-weight: 600;
        }}
        .two-col {{
            display: grid;
            grid-template-columns: 1fr 1fr;
            gap: 2rem;
        }}
        @media(max-width: 768px) {{
            .two-col {{ grid-template-columns: 1fr; }}
        }}
        .table-container {{
            background: var(--card-bg);
            border: 1px solid var(--border-color);
            border-radius: 16px;
            padding: 1.25rem;
            max-height: 400px;
            overflow-y: auto;
        }}
        table {{
            width: 100%;
            border-collapse: collapse;
            text-align: left;
        }}
        th {{
            padding: 0.75rem 1rem;
            font-weight: 600;
            color: var(--text-muted);
            border-bottom: 1px solid var(--border-color);
        }}
        td {{
            padding: 0.75rem 1rem;
            border-bottom: 1px solid rgba(255, 255, 255, 0.03);
            font-size: 0.9rem;
            white-space: nowrap;
            overflow: hidden;
            text-overflow: ellipsis;
            max-width: 250px;
        }}
        .badge {{
            display: inline-block;
            padding: 0.25rem 0.5rem;
            border-radius: 6px;
            font-size: 0.8rem;
            font-weight: 600;
        }}
        .badge-success {{ background: rgba(16, 185, 129, 0.15); color: var(--accent-green); }}
        .badge-fail {{ background: rgba(239, 68, 68, 0.15); color: var(--accent-red); }}
    </style>
</head>
<body>
    <div class="container">
        <header>
            <div>
                <h1>The Polite Scraper Observability</h1>
                <p style="color: var(--text-muted); margin-top: 0.25rem;">A real-time health and scraping metrics reporter.</p>
            </div>
            <div class="timestamp">
                Last Scraped: {report["start_time"]}
            </div>
        </header>

        <!-- Main Stats Grid -->
        <div class="grid">
            <div class="card">
                <div class="card-title">Scrape Health</div>
                <div class="card-value text-green">{(1.0 - (report["failed_pages"] / (report["valid_records"] + report["failed_pages"] or 1))) * 100:.1f}%</div>
                <p style="font-size: 0.85rem; color: var(--text-muted); margin-top: 0.5rem;">{report["valid_records"]} succeeded / {report["failed_pages"]} failed</p>
            </div>
            <div class="card">
                <div class="card-title">Execution Duration</div>
                <div class="card-value text-blue">{report["duration_seconds"]}s</div>
                <p style="font-size: 0.85rem; color: var(--text-muted); margin-top: 0.5rem;">{report["pages_fetched"]} network / {report["cache_hits"]} cache hits</p>
            </div>
            <div class="card">
                <div class="card-title">Average Book Price</div>
                <div class="card-value text-purple">£{avg_price:.2f}</div>
                <p style="font-size: 0.85rem; color: var(--text-muted); margin-top: 0.5rem;">Range: £{min_price:.2f} - £{max_price:.2f}</p>
            </div>
            <div class="card">
                <div class="card-title">Change Detection</div>
                <div class="card-value text-blue">+{changes["new"]} / ~{changes["changed"]}</div>
                <p style="font-size: 0.85rem; color: var(--text-muted); margin-top: 0.5rem;">Unchanged: {changes["unchanged"]} | Gone: {changes["gone"]}</p>
            </div>
        </div>

        <div class="two-col">
            <!-- Valid Scraped Books Summary -->
            <div>
                <h2 class="section-title">Latest Scraped Books</h2>
                <div class="table-container">
                    <table>
                        <thead>
                            <tr>
                                <th>Title</th>
                                <th>Price</th>
                                <th>Rating</th>
                                <th>Availability</th>
                            </tr>
                        </thead>
                        <tbody>
                            {"".join([f'<tr><td title="{b["title"]}">{b["title"]}</td><td>£{b["price_gbp"]:.2f}</td><td>{b["rating_text"]}</td><td>{b["availability_text"]}</td></tr>' for b in books_data[:15]])}
                        </tbody>
                    </table>
                </div>
            </div>

            <!-- Failures and Logs -->
            <div>
                <h2 class="section-title">Encountered Failures / Skips</h2>
                <div class="table-container">
                    <table>
                        <thead>
                            <tr>
                                <th>Target URL</th>
                                <th>Reason for Skip</th>
                                <th>Status</th>
                            </tr>
                        </thead>
                        <tbody>
                            {"".join([f'<tr><td><a href="{err["product_url"]}" target="_blank" style="color: var(--accent-blue); text-decoration: none;">{err["product_url"].split("/")[-2]}</a></td><td title="{err["error_reason"]}">{err["error_reason"][:40]}...</td><td><span class="badge badge-fail">Failed</span></td></tr>' for err in errors_data]) if errors_data else '<tr><td colspan="3" style="text-align: center; color: var(--text-muted);">No scraping failures recorded. Everything is 100% green!</td></tr>'}
                        </tbody>
                    </table>
                </div>
            </div>
        </div>
    </div>
</body>
</html>"""
    
    with open(html_path, "w", encoding="utf-8") as f:
        f.write(html_content)

def main():
    start_time = datetime.now(timezone.utc)
    start_time_iso = start_time.isoformat()
    start_perf = time.perf_counter()
    
    log_structured("INFO", "Starting Polite Scraper Pipeline Execution.")
    
    start_url = "https://books.toscrape.com/catalogue/page-1.html"
    try:
        # Step 1: Crawl catalogue pages (1-3)
        book_targets = discover_book_urls(start_url)
        
        # Step 4: Inject a fake/broken URL for failure demonstration (Stage 5)
        fake_book = {
            "url": "https://books.toscrape.com/catalogue/non_existent_book_9999/index.html",
            "source_page": "https://books.toscrape.com/catalogue/page-3.html"
        }
        book_targets.append(fake_book)
        log_structured("INFO", f"Injected fake book URL for failure proof: {fake_book['url']}")
        
        books_data = []
        errors_data = []
        
        # Step 2: Loop detail pages with try-except to isolate failures
        for book in book_targets:
            url = book["url"]
            source_page = book["source_page"]
            
            cache_file = f"cache/detail-{clean_filename(url)}"
            fetched_at = datetime.now(timezone.utc).isoformat()
            
            try:
                # Fetch details HTML (retries on 5xx/timeouts, ignores 404, or loads from cache)
                html_content = fetch_with_cache(url, cache_file)
                
                # Extract raw record fields
                raw_record = extract_raw_book_details(html_content, url, source_page, fetched_at)
                
                # Clean/normalize price
                price_gbp = normalize_price(raw_record["price_text"])
                
                # Combine raw fields and clean fields for Pydantic validation
                clean_record_data = {
                    **raw_record,
                    "price_gbp": price_gbp
                }
                
                # Validate against Pydantic schema
                validated_record = BookRecord(**clean_record_data)
                books_data.append(json.loads(validated_record.model_dump_json()))
                
            except Exception as e:
                # Isolation: log and skip broken records/fetches, direct to errors.json
                error_msg = str(e)
                log_structured("ERROR", f"Failed detail page extraction on {url}", {"url": url, "error": error_msg})
                errors_data.append({
                    "product_url": url,
                    "error_reason": error_msg,
                    "timestamp": fetched_at
                })
                
        # output directory ensure
        os.makedirs("output", exist_ok=True)
        books_json_path = "output/books.json"
        
        # Change Detection comparison (Extra 2)
        changes = detect_changes(books_data, books_json_path)
        log_structured("INFO", "Change detection comparison complete.", changes)
        
        # Save validated JSON records (idempotent overwrite)
        with open(books_json_path, "w", encoding="utf-8") as f:
            json.dump(books_data, f, indent=2)
            
        errors_path = "output/errors.json"
        with open(errors_path, "w", encoding="utf-8") as f:
            json.dump(errors_data, f, indent=2)
            
        # CSV Export (Extra 1)
        csv_path = "output/books.csv"
        export_to_csv(books_data, csv_path)
        log_structured("INFO", f"Books successfully exported to CSV.", {"csv_path": csv_path})
            
        # Write execution run-report.json
        duration_sec = time.perf_counter() - start_perf
        run_report = {
            "start_time": start_time_iso,
            "duration_seconds": round(duration_sec, 2),
            "pages_fetched": stats["pages_fetched"],
            "cache_hits": stats["cache_hits"],
            "valid_records": len(books_data),
            "invalid_records": len(errors_data),
            "failed_pages": stats["failed_pages"]
        }
        
        report_path = "output/run-report.json"
        with open(report_path, "w", encoding="utf-8") as f:
            json.dump(run_report, f, indent=2)
            
        # HTML Dashboard Generation (Extra 3)
        dashboard_path = "output/dashboard.html"
        generate_dashboard(run_report, changes, books_data, errors_data, dashboard_path)
        log_structured("INFO", f"Dashboard HTML generated successfully.", {"dashboard_path": dashboard_path})
            
        print("\n--- MAKE IT YOURS EXTRAS EXECUTED ---")
        print(f"Validated JSON Output: {books_json_path} ({len(books_data)} records)")
        print(f"Flat CSV Output: {csv_path}")
        print(f"Observability HTML Dashboard: {dashboard_path}")
        print(f"Structured logs written to: output/scraper.log")
        
        # Verify checkpoint assertions
        assert len(books_data) == 60, f"Expected 60 validated records, got {len(books_data)}"
        assert run_report["failed_pages"] == 1, "Expected 1 failed page due to failure injection"
        print("\nAll extra checkpoints passed successfully!")
            
    except Exception as e:
        log_structured("CRITICAL", f"Execution failed: {str(e)}")

if __name__ == "__main__":
    main()
