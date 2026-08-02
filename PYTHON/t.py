from reportlab.pdfgen import canvas

# Define the output file name
output_file = "output.pdf"

# Create a canvas object
c = canvas.Canvas(output_file, pagesize=(612, 792))  # Default size: 8.5 x 11 inches

# Add some text to the PDF
c.setFont("Helvetica", 12)
c.drawString(100, 600, "Click the link below to watch the video:")

# Draw a rectangle around the link area (optional for visibility)
x1, y1 = 100, 550  # Bottom-left corner
x2, y2 = 300, 570  # Top-right corner
c.setStrokeColorRGB(0, 0, 1)  # Blue border
c.setFillColorRGB(0.9, 0.9, 1)  # Light blue fill
c.rect(x1, y1, x2 - x1, y2 - y1, fill=1)  # Draw rectangle with fill

# Add the clickable link
c.linkURL("https://www.youtube.com/watch?v=KVyGiJajRtg", (x1, y1, x2, y2), relative=0)

# Save the PDF
c.save()

print(f"PDF created successfully with a clickable link! Check '{output_file}'.")
