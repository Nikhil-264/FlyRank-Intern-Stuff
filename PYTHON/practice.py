import PyPDF2

# Create a new PDF file
pdf = PyPDF2.PdfFileWriter()

# Add a new page to the PDF
page = pdf.addBlankPage(width=200, height=200)

# Set the content of the page
content = "Hello guys"
page.mergePage(content)

# Save the PDF to a file
with open("DSA_CompleteNotes.pdf", "wb") as f:
    pdf.write(f)
