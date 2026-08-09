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

# Step 3: Define Pydantic Schema for a finished book record
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
    """Fetch HTML from the cache if it exists, otherwise download and save it politely."""
    # Ensure cache folder exists
    os.makedirs(os.path.dirname(cache_path), exist_ok=True)
    
    # Check if we have a cached copy
    if os.path.exists(cache_path):
        size = os.path.getsize(cache_path)
        print(f"CACHE HIT: {url} (size={size} bytes)")
        with open(cache_path, "r", encoding="utf-8") as f:
            return f.read()
            
    # Politely delay before hitting the server (cache misses only)
    time.sleep(DELAY)
    
    # Fetch from server
    headers = {"User-Agent": USER_AGENT}
    try:
        response = requests.get(url, headers=headers, timeout=TIMEOUT)
        
        # Check HTTP status code (must be 200)
        if response.status_code != 200:
            raise RuntimeError(f"HTTP error {response.status_code} while fetching {url}")
            
        html_content = response.text
        
        # Save html payload to cache file
        with open(cache_path, "w", encoding="utf-8") as f:
            f.write(html_content)
            
        print(f"FETCH: {url} (size={len(html_content)} bytes)")
        return html_content
        
    except requests.RequestException as e:
        raise RuntimeError(f"Failed to connect or fetch page {url}: {e}")

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
            
    # Step 2: Remove duplicate links while preserving order
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

# Step 1: Normalizer function for price strings
def normalize_price(price_text: str) -> float:
    """Extract digits and decimals from the price text (e.g., '£51.77' -> 51.77)."""
    match = re.search(r'[\d.]+', price_text)
    if match:
        return float(match.group())
    raise ValueError(f"Could not extract numeric price from '{price_text}'")

def main():
    start_url = "https://books.toscrape.com/catalogue/page-1.html"
    try:
        # Step 1: Crawl catalogue pages (1-3)
        book_targets = discover_book_urls(start_url)
        print(f"\nDiscovered {len(book_targets)} unique book detail URLs. Starting extraction & validation...")
        
        books_data = []
        errors_data = []
        
        # Step 2: Fetch, extract, normalize, and validate all book detail pages
        for book in book_targets:
            url = book["url"]
            source_page = book["source_page"]
            
            cache_file = f"cache/detail-{clean_filename(url)}"
            fetched_at = datetime.now(timezone.utc).isoformat()
            
            try:
                # Fetch details HTML
                html_content = fetch_with_cache(url, cache_file)
                
                # Extract raw record fields
                raw_record = extract_raw_book_details(html_content, url, source_page, fetched_at)
                
                # Step 1: Clean/normalize price
                price_gbp = normalize_price(raw_record["price_text"])
                
                # Combine raw fields and clean fields for Pydantic validation
                clean_record_data = {
                    **raw_record,
                    "price_gbp": price_gbp
                }
                
                # Step 4: Validate against Pydantic schema
                validated_record = BookRecord(**clean_record_data)
                
                # Serialize Pydantic model to dict safely (turns HttpUrl/datetime into strings)
                # Pydantic v2 model_dump_json() / json.loads
                books_data.append(json.loads(validated_record.model_dump_json()))
                
            except (ValidationError, Exception) as e:
                # Step 4: Record schema validation failures and fetch errors to errors.json
                print(f"VALIDATION FAILURE: {url} - Error: {e}")
                errors_data.append({
                    "product_url": url,
                    "error_reason": str(e),
                    "timestamp": fetched_at
                })
                
        # Step 5: Save outputs (idempotent overwrite)
        os.makedirs("output", exist_ok=True)
        
        books_path = "output/books.json"
        with open(books_path, "w", encoding="utf-8") as f:
            json.dump(books_data, f, indent=2)
            
        errors_path = "output/errors.json"
        with open(errors_path, "w", encoding="utf-8") as f:
            json.dump(errors_data, f, indent=2)
            
        # Checkpoint outputs
        print("\n--- STAGE 4 CHECKPOINT ---")
        print(f"books.json written to: {books_path} (count={len(books_data)})")
        print(f"errors.json written to: {errors_path} (count={len(errors_data)})")
        
        # Verify schema guarantees:
        if books_data:
            sample = books_data[0]
            print("\nSample validated record from books.json:")
            print(json.dumps(sample, indent=2))
            
            # Simple assertions for checkpoint proof
            assert len(books_data) == 60, f"Expected 60 records, got {len(books_data)}"
            assert isinstance(sample["price_gbp"], float), "price_gbp must be a float number"
            assert sample["product_url"].startswith("https://"), "product_url must start with https://"
            print("\nCheckpoint verification passed successfully!")
            
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
