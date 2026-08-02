import os
from yt_dlp import YoutubeDL

def download_video(url, save_path):
    # Ensure the directory exists
    os.makedirs(save_path, exist_ok=True)

    ydl_opts = {
        'format': 'best',
        'outtmpl': os.path.join(save_path, '%(title)s.%(ext)s'),
    }

    try:
        with YoutubeDL(ydl_opts) as ydl:
            ydl.download([url])
        print("Video downloaded successfully!")
    except Exception as e:
        print(f"Error: {e}")

# Provide the URL and save path
url = "https://www.youtube.com/watch?v=d72vXhJDE6M"
save_path = r"C:\Users\HP\Videos\Youtube_Videos"  # Use raw string to avoid issues

download_video(url, save_path)
