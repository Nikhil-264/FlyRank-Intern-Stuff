# The Polite Scraper

A polite and idempotent web scraping pipeline built as part of Backend Track Week 5 Assignment A9 to practice target classification, fetching, extraction, normalization, validation, and error reporting.

## Target Classification

- **Target Site**: [Books to Scrape](https://books.toscrape.com/)
- **Reason for Scraping**: Education and scraping practice sandbox. The site explicitly states it is a sandbox built for people to practice scraping.
- **Scope**: The first 3 catalogue pages containing 20 books each (60 books in total).
- **Robots.txt Result**: Requesting `https://books.toscrape.com/robots.txt` returned a **404 Not Found** ("no robots file found"). A missing robots file is not explicit permission, but it indicates no specific exclusion rules are declared by the server.
- **Data Collected**: Book title, detail product URL, raw and normalized price (GBP), availability text, rating, description, source catalogue page, and fetched timestamp.
- **Appropriateness**: This collection is appropriate because the target is a public sandbox environment built exactly for practicing scraping, no login or paywalls are bypassed, the scope is small (60 books), and we will access pages politely with rate delays and caching.

> "I will not reuse this code on another site without checking its rules and terms first."

---

## Run Instructions

(To be finalized in Stage 6)
