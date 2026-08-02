from ebooklib import epub
from bs4 import BeautifulSoup
from fpdf import FPDF

# Define file paths
epub_path = r"C:\Users\HP\Downloads\The Hard Thing About Hard Things_ Building a Business When There Are No Easy Answers ( PDFDrive ) (1).epub"
pdf_path = r"E:\The Hard Thing About Hard Things.pdf"

# Load EPUB book
book = epub.read_epub(epub_path)
pdf = FPDF()
pdf.set_auto_page_break(auto=True, margin=15)

# Set a UTF-8 compatible font
pdf.set_font("Times", size=12)  # Default font that works in most cases

# Extract text from EPUB
for item in book.get_items():
    if item.get_type() == epub.ITEM_DOCUMENT:
        soup = BeautifulSoup(item.content, "html.parser")
        text = soup.get_text().strip()

        if text:
            pdf.add_page()
            pdf.multi_cell(0, 10, text)

# Save as PDF
pdf.output(pdf_path, "F")
print(f"PDF saved at: {pdf_path}")
