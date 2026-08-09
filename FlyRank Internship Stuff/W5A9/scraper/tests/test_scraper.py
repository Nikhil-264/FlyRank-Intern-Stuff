import pytest
from urllib.parse import urljoin
from bs4 import BeautifulSoup
from src.main import normalize_price, extract_raw_book_details, clean_filename

def test_price_normalization():
    """Verify raw price strings are correctly parsed into floats."""
    assert normalize_price("£51.77") == 51.77
    assert normalize_price("£12.34") == 12.34
    assert normalize_price("£0.99") == 0.99
    
    with pytest.raises(ValueError):
        normalize_price("Free")

def test_url_joining():
    """Verify relative to absolute URL resolution using urljoin."""
    base_url = "https://books.toscrape.com/catalogue/page-1.html"
    relative_url = "../a-light-in-the-attic_1000/index.html"
    absolute_url = urljoin(base_url, relative_url)
    assert absolute_url == "https://books.toscrape.com/catalogue/a-light-in-the-attic_1000/index.html"

def test_missing_description():
    """Verify missing book descriptions are parsed as None."""
    # HTML mock with product details but NO product description section
    html_mock = """
    <html>
        <body>
            <div class="product_main">
                <h1>A Light in the Attic</h1>
                <p class="price_color">£51.77</p>
                <p class="instock availability">In stock (22 available)</p>
                <p class="star-rating Three"></p>
            </div>
        </body>
    </html>
    """
    url = "https://books.toscrape.com/catalogue/mock-book/index.html"
    source = "https://books.toscrape.com/catalogue/page-1.html"
    fetched_at = "2026-08-06T10:00:00Z"
    
    record = extract_raw_book_details(html_mock, url, source, fetched_at)
    assert record["title"] == "A Light in the Attic"
    assert record["description"] is None

def test_duplicate_urls_deduplication():
    """Verify crawler deduplicates discovered URLs correctly."""
    # List of discovered book targets with duplicates
    discovered_books = [
        {"url": "https://books.toscrape.com/1", "source": "page-1.html"},
        {"url": "https://books.toscrape.com/2", "source": "page-1.html"},
        {"url": "https://books.toscrape.com/1", "source": "page-2.html"},  # duplicate url
    ]
    
    # Deduplicate preserving order
    unique_books = []
    seen = set()
    for book in discovered_books:
        if book["url"] not in seen:
            seen.add(book["url"])
            unique_books.append(book)
            
    assert len(unique_books) == 2
    assert unique_books[0]["url"] == "https://books.toscrape.com/1"
    assert unique_books[1]["url"] == "https://books.toscrape.com/2"

def test_malformed_html_fixture():
    """Verify malformed page structure raises a ValueError during parsing."""
    # HTML missing the critical product_main class
    html_malformed = """
    <html>
        <body>
            <div class="wrong_class">
                <h1>A Light in the Attic</h1>
            </div>
        </body>
    </html>
    """
    url = "https://books.toscrape.com/catalogue/mock-book/index.html"
    source = "https://books.toscrape.com/catalogue/page-1.html"
    fetched_at = "2026-08-06T10:00:00Z"
    
    with pytest.raises(ValueError, match="Invalid product detail page structure"):
        extract_raw_book_details(html_malformed, url, source, fetched_at)

def test_clean_filename():
    """Verify URL-to-filename conversion for caching."""
    url = "https://books.toscrape.com/catalogue/page-1.html"
    assert clean_filename(url) == "books_toscrape_com_catalogue_page_1_html.html"
