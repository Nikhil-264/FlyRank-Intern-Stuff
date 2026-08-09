import os
import time
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin

# Config: Honest user-agent and timeout (polite scraping settings)
USER_AGENT = "FlyRankInternship-A9/1.0 (+https://github.com/Nikhil-264/FlyRank-Intern-Stuff)"
TIMEOUT = 10
DELAY = 0.5  # 500ms delay between real requests

def fetch_with_cache(url: str, cache_path: str) -> str:
    """Fetch HTML from the cache if it exists, otherwise download and save it."""
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
    """Dynamically traverse catalogue pages 1 to 3 and collect book URLs."""
    current_url = start_url
    page_num = 1
    discovered_books = []
    
    while current_url and page_num <= 3:
        cache_path = f"cache/catalogue-page-{page_num}.html"
        
        # Fetch the page (polite fetching with cache)
        html_content = fetch_with_cache(current_url, cache_path)
        
        # Parse the page
        soup = BeautifulSoup(html_content, "html.parser")
        
        # Extract relative links for books
        # HTML structure: <article class="product_pod"> <h3> <a href="...">
        articles = soup.find_all("article", class_="product_pod")
        for article in articles:
            link_el = article.find("h3").find("a")
            relative_url = link_el.get("href")
            
            # Resolve to absolute URL (never string gluing)
            absolute_url = urljoin(current_url, relative_url)
            discovered_books.append(absolute_url)
            
        # Find the "next" page link dynamically
        next_button = soup.find("li", class_="next")
        if next_button:
            next_relative_url = next_button.find("a").get("href")
            current_url = urljoin(current_url, next_relative_url)
            page_num += 1
        else:
            current_url = None
            
    # Remove duplicate links while preserving order
    unique_urls = []
    seen = set()
    for url in discovered_books:
        if url not in seen:
            seen.add(url)
            unique_urls.append(url)
            
    # Checkpoint output
    print(f"\ncatalogue_pages={page_num}, discovered={len(discovered_books)}, unique_urls={len(unique_urls)}")
    return unique_urls

def main():
    start_url = "https://books.toscrape.com/catalogue/page-1.html"
    try:
        discover_book_urls(start_url)
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
