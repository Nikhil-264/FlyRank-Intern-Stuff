# The Polite Scraper

A polite, idempotent, and fault-tolerant web scraping pipeline built as part of Backend Track Week 5 Assignment A9 to practice target classification, fetching, extraction, normalization, validation, and execution reporting.

---

## 1. Target Classification

- **Target Site**: [Books to Scrape](https://books.toscrape.com/)
- **Reason for Scraping**: Education and scraping practice sandbox. The site explicitly states it is a sandbox built for people to practice scraping.
- **Scope**: The first 3 catalogue pages containing 20 books each (60 books in total).
- **Robots.txt Result**: Requesting `https://books.toscrape.com/robots.txt` returned a **404 Not Found** ("no robots file found"). A missing robots file is not explicit permission, but it indicates no specific exclusion rules are declared by the server.
- **Data Collected**: Book title, detail product URL, raw and normalized price (GBP), availability text, rating, description, source catalogue page, and fetched timestamp.
- **Appropriateness**: This collection is appropriate because the target is a public sandbox environment built exactly for practicing scraping, no login or paywalls are bypassed, the scope is small (60 books), and we will access pages politely with rate delays and caching.

> "I will not reuse this code on another site without checking its rules and terms first."

---

## 2. Installation & Setup

This project uses the **Python lane** with `requests`, `beautifulsoup4`, and `pydantic`.

### Prerequisites
- Python 3.10+
- A terminal (PowerShell, Command Prompt, or terminal of choice)

### Steps
1. Navigate into the scraper folder:
   ```bash
   cd scraper
   ```
2. Create and activate a Python virtual environment:
   ```bash
   python -m venv .venv
   # On Windows (PowerShell):
   .\.venv\Scripts\Activate.ps1
   # On macOS/Linux:
   source .venv/bin/activate
   ```
3. Install the dependencies:
   ```bash
   pip install -r requirements.txt
   ```

---

## 3. Run Command

To execute the scraping pipeline, run the following command from the `scraper` folder:
```bash
python src/main.py
```
This will:
- Discover all unique book detail page links from the first 3 catalogue pages.
- Download and cache the HTML files locally in a `cache/` directory.
- Extract detail fields, normalize values, and validate them against the Pydantic schema.
- Store results in `output/books.json` and validation errors in `output/errors.json`.
- Output execution metrics to `output/run-report.json`.

To run the unit test suite (stretch goal):
```bash
pytest tests/test_scraper.py
```

---

## 4. Record Schema

The schema of each clean book record saved in `output/books.json` is validated by Pydantic:

| Field Name | Type | Description |
| :--- | :--- | :--- |
| `title` | `str` | Title of the book (non-empty). |
| `product_url` | `HttpUrl` (string) | Canonical absolute URL of the book. |
| `price_text` | `str` | Original raw price string (e.g. `"£51.77"`). |
| `price_gbp` | `float` | Normalized float price value (e.g. `51.77`). |
| `availability_text` | `str` | Raw stock availability text. |
| `rating_text` | `str` | Book star rating text (one of `"One"`, `"Two"`, `"Three"`, `"Four"`, `"Five"`). |
| `description` | `str` or `null` | Book summary text (optional, set to `null` if missing). |
| `source_page` | `HttpUrl` (string) | URL of the catalogue page where the book was discovered (provenance). |
| `fetched_at` | `ISO datetime` (string) | UTC Timestamp of when the book detail page was fetched (provenance). |

---

## 5. Politeness Rules

We practice polite guest habits to avoid server overload:
1. **Descriptive User-Agent**: We identify our robot in headers:
   `FlyRankInternship-A9/1.0 (+https://github.com/Nikhil-264/FlyRank-Intern-Stuff)`
2. **Rate Limiting / Delays**: We enforce a `500ms` sleep delay between consecutive network requests.
3. **Request Timeouts**: We enforce a `10s` timeout limit on requests to prevent hanging forever.
4. **Local Page Caching**: Pages are saved under `cache/` on disk. If a page exists locally, the scraper reads the cached copy without making a network request.

---

## 6. Execution Evidence (Run Report)

Below is the real `output/run-report.json` showing a complete execution run (in this run, 1 fake URL was intentionally injected to verify error isolation):

```json
{
  "start_time": "2026-08-09T06:10:56.664536+00:00",
  "duration_seconds": 1.89,
  "pages_fetched": 0,
  "cache_hits": 63,
  "valid_records": 60,
  "invalid_records": 1,
  "failed_pages": 1
}
```

---

## 7. Architectural Decisions & Ethics

### Why no browser is needed
This assignment needed no browser because all target data is already present in the HTML sent by the server; using a browser-based automation tool like Selenium or Playwright would only add CPU and memory overhead without any benefit.

### Scraper Ethics Note
Web scraping must always be done responsibly. We should:
- Respect server capacity by using proper rate-limiting delays and local caching.
- Look for official APIs first and use them if they exist.
- Never attempt to bypass access logins, paywalls, or blocks.
- Respect the rules declared in a site's `robots.txt` file.
- Collect only the minimum subset of data required for our project.

### Honest Limitation
The crawler relies on a fixed HTML class structure (`product_pod`, `product_main`, etc.). If the target site updates its template layout, selectors will need to be re-mapped. Additionally, the catalogue traversal is currently scoped strictly to the first 3 pages and is not configured for generic site-wide crawling.
