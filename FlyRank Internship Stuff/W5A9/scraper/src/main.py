import os
import re
import time
import json
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from datetime import datetime, timezone
from pydantic import BaseModel, Field, HttpUrl, ValidationError
from typing import Optional

# Config: Honest user-agent and timeout (polite scraping settings)
USER_AGENT = "FlyRankInternship-A9/1.0 (+https://github.com/Nikhil-264/FlyRank-Intern-Stuff)"
TIMEOUT = 10
DELAY = 0.5  # 500ms delay between real requests

# Global metrics tracker (Stage 5)
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

def clean_filename(url: str) -> str:
    """Convert a URL to a safe filename for local caching."""
    clean = re.sub(r'https?://(www\.)?', '', url)
    clean = re.sub(r'[^a-zA-Z0-9_\-]', '_', clean)
    return f"{clean}.html"

def fetch_with_cache(url: str, cache_path: str) -> str:
    """Fetch HTML from cache or server politely, retrying on 5xx/timeouts (Stage 5)."""
    # Ensure cache folder exists
    os.makedirs(os.path.dirname(cache_path), exist_ok=True)
    
    # Check if we have a cached copy
    if os.path.exists(cache_path):
        stats["cache_hits"] += 1
        print(f"CACHE HIT: {url} (size={os.path.getsize(cache_path)} bytes)")
        with open(cache_path, "r", encoding="utf-8") as f:
            return f.read()
            
    # Polite retry loop (timeout & 5xx)
    headers = {"User-Agent": USER_AGENT}
    max_attempts = 2  # Original request + 1 retry
    
    for attempt in range(1, max_attempts + 1):
        # Politely delay before hitting the server (cache misses only)
        time.sleep(DELAY)
        
        try:
            print(f"FETCH: {url} (Attempt {attempt}/{max_attempts})")
            response = requests.get(url, headers=headers, timeout=TIMEOUT)
            
            # Status check (Stage 1 & 5)
            if response.status_code == 200:
                stats["pages_fetched"] += 1
                html_content = response.text
                
                # Save to cache
                with open(cache_path, "w", encoding="utf-8") as f:
                    f.write(html_content)
                return html_content
            
            # Retry only on Server Error (5xx)
            elif 500 <= response.status_code < 600:
                print(f"SERVER ERROR ({response.status_code}) on {url}.")
                if attempt < max_attempts:
                    print("Retrying in 1 second...")
                    time.sleep(1)
                    continue
            
            # Client errors (404/403) are skipped immediately
            else:
                print(f"CLIENT ERROR ({response.status_code}) on {url}. Skipping (no retry).")
                break
                
        except (requests.Timeout, requests.RequestException) as e:
            print(f"NETWORK ERROR ({type(e).__name__}) on {url}.")
            if attempt < max_attempts:
                print("Retrying in 1 second...")
                time.sleep(1)
                continue
                
    # If all attempts fail, log it and raise error to skip page
    stats["failed_pages"] += 1
    raise RuntimeError(f"Failed to fetch page {url} after {max_attempts} attempts.")

def discover_book_urls(start_url: str) -> list:
    """Dynamically traverse catalogue pages 1 to 3 and collect book URLs and their source page."""
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

def main():
    start_time = datetime.now(timezone.utc)
    start_time_iso = start_time.isoformat()
    start_perf = time.perf_counter()
    
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
        print(f"\n[FAILURE INJECTION] Appended fake URL to targets: {fake_book['url']}")
        print(f"Starting extraction & validation loop for {len(book_targets)} targets...")
        
        books_data = []
        errors_data = []
        
        # Step 2: Loop detail pages with try-except to isolate failures (Stage 5)
        for book in book_targets:
            url = book["url"]
            source_page = book["source_page"]
            
            cache_file = f"cache/detail-{clean_filename(url)}"
            fetched_at = datetime.now(timezone.utc).isoformat()
            
            try:
                # Fetch details HTML (will retry 5xx/timeouts, fail on 404, or load from cache)
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
                # Isolation: log and skip broken records/fetches, direct to errors.json (Stage 5)
                error_msg = str(e)
                print(f"SKIPPED PAGE [{url}] DUE TO ERROR: {error_msg}")
                errors_data.append({
                    "product_url": url,
                    "error_reason": error_msg,
                    "timestamp": fetched_at
                })
                
        # Save outputs (idempotent overwrite)
        os.makedirs("output", exist_ok=True)
        
        books_path = "output/books.json"
        with open(books_path, "w", encoding="utf-8") as f:
            json.dump(books_data, f, indent=2)
            
        errors_path = "output/errors.json"
        with open(errors_path, "w", encoding="utf-8") as f:
            json.dump(errors_data, f, indent=2)
            
        # Step 3: Write execution run-report.json (Stage 5)
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
            
        # Checkpoint outputs
        print("\n--- STAGE 5 CHECKPOINT ---")
        print(f"Scraper finished execution. Run report:")
        print(json.dumps(run_report, indent=2))
        print(f"\nbooks.json count: {len(books_data)} (Expected 60)")
        print(f"errors.json count: {len(errors_data)} (Expected 1 due to fake URL)")
        
        # Checkpoint verification assertions
        assert len(books_data) == 60, f"Expected 60 validated records, got {len(books_data)}"
        assert run_report["failed_pages"] == 1, f"Expected 1 failed page (fake URL), got {run_report['failed_pages']}"
        print("\nStage 5 checkpoint verification passed successfully!")
            
    except Exception as e:
        print(f"Critical error during execution: {e}")

if __name__ == "__main__":
    main()
