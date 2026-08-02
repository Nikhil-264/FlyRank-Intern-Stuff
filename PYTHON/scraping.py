import requests
from bs4 import BeautifulSoup
import gspread
from oauth2client.service_account import ServiceAccountCredentials

# URL of IIT KGP Deans page
url = "https://www.iitkgp.ac.in/deans"

# Fetch the page content
response = requests.get(url)
soup = BeautifulSoup(response.text, "html.parser")

# Extract all divs containing dean information
dean_divs = soup.find_all("div", class_="col-md-6")

deans_data = []
for div in dean_divs:
    name = div.find("h3").text.strip() if div.find("h3") else "N/A"
    position = div.find("h4").text.strip() if div.find("h4") else "N/A"
    
    # Extract email and contact from <p> tags
    p_tags = div.find_all("p")
    department = p_tags[0].text.strip() if len(p_tags) > 0 else "N/A"
    contact = p_tags[1].text.strip() if len(p_tags) > 1 else "N/A"
    email = p_tags[2].text.strip() if len(p_tags) > 2 else "N/A"

    deans_data.append([name, position, department, contact, email])

# Google Sheets API setup
scope = ["https://spreadsheets.google.com/feeds", "https://www.googleapis.com/auth/drive"]
credentials = ServiceAccountCredentials.from_json_keyfile_name("your_credentials.json", scope)
client = gspread.authorize(credentials)

# Open Google Sheet (replace with actual sheet name)
sheet = client.open("Deans List IIT KGP").sheet1

# Clear old data and update sheet
sheet.clear()
sheet.append_row(["Name", "Position", "Department", "Office Contact", "Email"])  # Headers
sheet.insert_rows(deans_data, 2)  # Insert new data

print("Data extracted and uploaded to Google Sheets successfully!")
