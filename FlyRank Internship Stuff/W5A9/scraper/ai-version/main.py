import os
import re
import sys
import json
import time
import requests
from bs4 import BeautifulSoup
from urllib.parse import urljoin
from datetime import datetime
from pydantic import BaseModel, Field, HttpUrl
from typing import Optional, List

# AI Generated Configuration
BASE_URL = "https://books.toscrape.com/catalogue/page-1.html"
USER_AGENT = "FlyRankInternship-A9/1.0"
TIMEOUT = 10
DELAY = 0.5

# Pydantic validation schema
class BookSchema(BaseModel):
    title: str
    product_url: HttpUrl
    price_text: str
    price_gbp: float = Field(gt=0)
    availability_text: str
    rating_text: str = Field(pattern="^(One|Two|Three|Four|Five)$")
    description: Optional[str] = None
    source_page: HttpUrl
    fetched_at: str  # AI simple string validation instead of datetime parser

class AIScraper:
    def __init__(self):
        self.cache_dir = "cache"
        self.output_dir = "output"
        self.pages_fetched = 0
        self.cache_hits = 0
        self.failed_pages = 0
        
        os.makedirs(self.cache_dir, exist_ok=True)
        os.makedirs(self.output_dir, exist_ok=True)

    def get_cache_filename(self, url: str) -> str:
        # AI simplified hashing for cache naming
        clean_url = re.sub(r'[^a-zA-Z0-9]', '_', url)
        return os.path.join(self.cache_dir, f"{clean_url}.html")

    def fetch_page(self, url: str) -> Optional[str]:
        cache_path = self.get_cache_filename(url)
        
        # Caching logic
        if os.path.exists(cache_path):
            self.cache_hits += 1
            with open(cache_path, "r", encoding="utf-8") as f:
                return f.read()

        # Politeness rate limiting
        time.sleep(DELAY)
        
        headers = {"User-Agent": USER_AGENT}
        
        # Retry logic (AI standard structure)
        for attempt in range(2):
            try:
                response = requests.get(url, headers=headers, timeout=TIMEOUT)
                if response.status_code == 200:
                    self.pages_fetched += 1
                    with open(cache_path, "w", encoding="utf-8") as f:
                        f.write(response.text)
                    return response.text
                elif response.status_code in [404, 403]:
                    # Do not retry on client errors
                    break
            except (requests.Timeout, requests.RequestException):
                if attempt == 1:
                    break
                time.sleep(1)  # wait 1s before retry
                
        self.failed_pages += 1
        return None

    def crawl_catalogue(self) -> List[dict]:
        current_url = BASE_URL
        discovered_books = []
        page_num = 1

        while current_url and page_num <= 3:
            html = self.fetch_page(current_url)
            if not html:
                break
            
            soup = BeautifulSoup(html, "html.parser")
            articles = soup.find_all("article", class_="product_pod")
            
            for article in articles:
                link_el = article.find("h3").find("a")
                relative_url = link_el.get("href")
                absolute_url = urljoin(current_url, relative_url)
                discovered_books.append({
                    "url": absolute_url,
                    "source": current_url
                })
                
            next_li = soup.find("li", class_="next")
            if next_li:
                next_url = next_li.find("a").get("href")
                current_url = urljoin(current_url, next_url)
                page_num += 1
            else:
                current_url = None

        # Deduplicate
        unique_books = []
        seen = set()
        for b in discovered_books:
            if b["url"] not in seen:
                seen.add(b["url"])
                unique_books.append(b)
                
        return unique_books

    def parse_book(self, html: str, url: str, source: str) -> dict:
        soup = BeautifulSoup(html, "html.parser")
        product_main = soup.find("div", class_="product_main")
        
        if not product_main:
            raise ValueError("product_main div not found")
            
        title = product_main.find("h1").text.strip()
        price_text = product_main.find("p", class_="price_color").text.strip()
        availability_text = product_main.find("p", class_="instock availability").text.strip()
        
        # Rating extraction
        rating_el = product_main.find("p", class_=re.compile("star-rating"))
        rating_text = ""
        if rating_el:
            for cls in rating_el.get("class", []):
                if cls != "star-rating":
                    rating_text = cls
                    break

        # Description extraction
        desc_div = soup.find("div", id="product_description")
        description = None
        if desc_div:
            desc_p = desc_div.find_next_sibling("p")
            if desc_p:
                description = desc_p.text.strip()

        return {
            "title": title,
            "product_url": url,
            "price_text": price_text,
            "availability_text": availability_text,
            "rating_text": rating_text,
            "description": description,
            "source_page": source,
            "fetched_at": datetime.utcnow().isoformat() + "Z"
        }

    def clean_price(self, price_text: str) -> float:
        match = re.search(r'[\d.]+', price_text)
        if match:
            return float(match.group())
        raise ValueError("No numeric price found")

    def run(self):
        start_time = datetime.utcnow()
        start_perf = time.perf_counter()
        
        # Crawl catalogue
        book_targets = self.crawl_catalogue()
        
        # Inject fake URL to test error isolation
        book_targets.append({
            "url": "https://books.toscrape.com/catalogue/fake_book_url_999/index.html",
            "source": "https://books.toscrape.com/catalogue/page-3.html"
        })
        
        books_data = []
        errors_data = []

        # Scrape books details
        for target in book_targets:
            url = target["url"]
            source = target["source"]
            
            try:
                html = self.fetch_page(url)
                if not html:
                    raise RuntimeError("Failed to fetch detail page")
                    
                raw_record = self.parse_book(html, url, source)
                price_gbp = self.clean_price(raw_record["price_text"])
                
                # Validation using Pydantic
                clean_record = {**raw_record, "price_gbp": price_gbp}
                validated = BookSchema(**clean_record)
                books_data.append(json.loads(validated.model_dump_json()))
                
            except Exception as e:
                errors_data.append({
                    "product_url": url,
                    "error_reason": str(e),
                    "timestamp": datetime.utcnow().isoformat() + "Z"
                })

        # Save files
        with open(os.path.join(self.output_dir, "books.json"), "w") as f:
            json.dump(books_data, f, indent=2)
        with open(os.path.join(self.output_dir, "errors.json"), "w") as f:
            json.dump(errors_data, f, indent=2)

        # Execution report
        duration = time.perf_counter() - start_perf
        report = {
            "start_time": start_time.isoformat() + "Z",
            "duration_seconds": round(duration, 2),
            "pages_fetched": self.pages_fetched,
            "cache_hits": self.cache_hits,
            "valid_records": len(books_data),
            "invalid_records": len(errors_data),
            "failed_pages": self.failed_pages
        }
        with open(os.path.join(self.output_dir, "run-report.json"), "w") as f:
            json.dump(report, f, indent=2)

        print("\n--- AI VERSION EXECUTION COMPLETED ---")
        print(json.dumps(report, indent=2))

if __name__ == "__main__":
    scraper = AIScraper()
    scraper.run()
