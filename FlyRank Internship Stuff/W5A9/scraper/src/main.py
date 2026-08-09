import os
import requests

# 1. Config: Honest user-agent and timeout (polite scraping settings)
USER_AGENT = "FlyRankInternship-A9/1.0 (+https://github.com/Nikhil-264/FlyRank-Intern-Stuff)"
TIMEOUT = 10  # Seconds to wait before giving up

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
            
    # Fetch from server politely if not cached
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

def main():
    target_url = "https://books.toscrape.com/catalogue/page-1.html"
    cache_file = "cache/catalogue-page-1.html"
    
    try:
        fetch_with_cache(target_url, cache_file)
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    main()
