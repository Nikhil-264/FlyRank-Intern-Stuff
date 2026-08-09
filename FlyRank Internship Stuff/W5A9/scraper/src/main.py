import os
import re
import time
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from datetime import datetime, timezone

# Config: Honest user-agent and timeout (polite scraping settings)
USER_AGENT = "FlyRankInternship-A9/1.0 (+https://github.com/Nikhil-264/FlyRank-Intern-Stuff)"
TIMEOUT = 10
DELAY = 0.5  # 500ms delay between real requests

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
    
    # Step 2: Aim selectors specifically at the product_main container
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
                
    # Step 3: Handle optional description (store None if missing)
    description_header = soup.find("div", id="product_description")
    description = None
    if description_header:
        desc_p = description_header.find_next_sibling("p")
        if desc_p:
            description = desc_p.text.strip()
            
    # Step 4: Include provenance metadata
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

def main():
    start_url = "https://books.toscrape.com/catalogue/page-1.html"
    try:
        # Step 1: Crawl catalogue pages (1-3)
        book_targets = discover_book_urls(start_url)
        print(f"\nDiscovered {len(book_targets)} unique book detail URLs. Starting detail page extraction...")
        
        raw_records = []
        detail_pages_count = 0
        
        # Step 2: Fetch and extract raw records for all 60 book detail pages
        for book in book_targets:
            url = book["url"]
            source_page = book["source_page"]
            
            # Create a safe file name for detail page caching
            cache_file = f"cache/detail-{clean_filename(url)}"
            
            # Fetch content (reads from local cache if it exists, otherwise requests politely)
            fetched_at = datetime.now(timezone.utc).isoformat()
            html_content = fetch_with_cache(url, cache_file)
            
            # Extract raw fields
            record = extract_raw_book_details(html_content, url, source_page, fetched_at)
            raw_records.append(record)
            detail_pages_count += 1
            
        # Checkpoint: print one raw record and summary count
        print("\n--- STAGE 3 CHECKPOINT ---")
        if raw_records:
            import json
            print("Sample raw record:")
            print(json.dumps(raw_records[0], indent=2))
        print(f"\ndetail_pages={detail_pages_count}")
        
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
