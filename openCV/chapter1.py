# save this as test_video.py

import cv2
import numpy as np

# Importing a video
# cap = cv2.VideoCapture('Resources/Minion_Dance_Video_Generated.mp4')

# while True:
#     success, img = cap.read()
#     if not success:
#         break
#     cv2.imshow("Video", img)
#     if cv2.waitKey(25) & 0xFF == ord('q'):
#         break

# cap.release()
# cv2.destroyAllWindows()

# Using webCam
# cap = cv2.VideoCapture(0)
# cap.set(3, 640)
# cap.set(4, 480)
# cap.set(10, 100)

# while True:
#     success, img = cap.read()   
#     cv2.imshow("Video", img)
#     if cv2.waitKey(1) & 0xFF == ord('q'):
#         break

# Basic Functions

# img = cv2.imread('Resources/me.jpg')
# kernel = np.ones((5, 5), np.uint16)

# scale_percent = 40  # percent of original size
# width = int(img.shape[1] * 20 / 100)
# height = int(img.shape[0] * 20 / 100)
# dim = (width, height)

# img_resized = cv2.resize(img, dim)

# imgGray = cv2.cvtColor(img_resized, cv2.COLOR_BGR2GRAY)
# imgBlur = cv2.GaussianBlur(img_resized, (3, 7), 0)
# imgCanny = cv2.Canny(img_resized, 200, 300)
# migDialation = cv2.dilate(imgCanny, kernel=kernel, iterations=1)
# imgEroded = cv2.erode(migDialation, kernel, iterations=1)

# cv2.imshow("Blurr Image", imgBlur)
# cv2.imshow("Grey Image", imgGray)
# cv2.imshow("Canny Image", imgCanny)
# cv2.imshow("dialation Image", migDialation)
# cv2.imshow("Eroded Image", imgEroded)
# cv2.waitKey(0)
# cv2.destroyAllWindows()
