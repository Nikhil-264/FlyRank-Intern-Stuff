from reportlab.pdfgen import canvas

# Define the output file name
output_file = "output_with_screen.pdf"

# Create a canvas object
c = canvas.Canvas(output_file, pagesize=(612, 792))  # Default size: 8.5 x 11 inches

# Add some text to the PDF
c.setFont("Helvetica", 14)
c.drawString(100, 700, "Embedded Video Placeholder:")

# Add a rectangle to represent the video screen
x1, y1 = 100, 500  # Bottom-left corner of the rectangle
x2, y2 = 400, 600  # Top-right corner of the rectangle
c.setStrokeColorRGB(0, 0, 0)  # Black border
c.setFillColorRGB(0.8, 0.8, 0.8)  # Light gray fill
c.rect(x1, y1, x2 - x1, y2 - y1, fill=1)  # Draw rectangle with fill

# Add a clickable link over the "screen"
c.linkURL("https://www.youtube.com/watch?v=KVyGiJajRtg", (x1, y1, x2, y2), relative=0)

# Save the PDF
c.save()

print(f"PDF created successfully with a placeholder screen and a clickable link! Check '{output_file}'.")
