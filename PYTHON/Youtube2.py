import os
from yt_dlp import YoutubeDL

def download_clip(url, save_path, start_time, end_time):
    os.makedirs(save_path, exist_ok=True)

    ydl_opts = {
        'format': 'bestvideo+bestaudio',
        'outtmpl': os.path.join(save_path, 'clip.mp4'),
        'download_sections': [f'*{start_time}-{end_time}'],
    }

    try:
        with YoutubeDL(ydl_opts) as ydl:
            ydl.download([url])
        print("Clip downloaded successfully!")
    except Exception as e:
        print(f"Error: {e}")

# Set video details
video_url = "https://www.youtube.com/watch?v=d72vXhJDE6M"
save_directory = r"C:\Users\HP\Videos\Youtube_Videos"
start_time = "9:45"
end_time = "9:49"

# Download the clip
download_clip(video_url, save_directory, start_time, end_time)
