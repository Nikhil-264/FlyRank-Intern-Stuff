import cv2
import numpy as np

# img = np.zeros((512, 512, 3), np.uint8)
# # print(img.shape)

# # Coloring Image

# # img[:] = 255, 0, 0

# cv2.line(img, (0, 0), (img.shape[1], img.shape[0]), (0, 255, 0), 3)
# # Above, the arguments are source, starting point, ending point, color, thickness

# cv2.rectangle(img, (0, 0), (250,  350), (0, 0, 255), cv2.FILLED)
# cv2.circle(img, (400, 50), 30, (255, 255, 0), 2)

# cv2.putText(img, "I Love openCV", (200, 100), cv2.FONT_HERSHEY_DUPLEX, 1, (0, 150, 0), 3)

# cv2.imshow("Image", img)

# cv2.waitKey(0)

# Chapter 5
# img = cv2.imread("Resources/misti.png")
# print(img.shape)
# width, height = 1600, 1600
# pts1 = np.float32([[339, 220], [1189, 186], [237, 1343], [1234, 1379]])
# # Getting specific square
# pts2 = np.float32([[0, 0], [width, 0], [0, height], [width, height]])

# matrix = cv2.getPerspectiveTransform(pts1, pts2)

# imageoutput = cv2.warpPerspective(img, matrix, (1600, 1600))

# cv2.imshow("Image", imageoutput)

# cv2.waitKey(0)


# Chapter 6

img = cv2. imread('Resources/misti.jpg' )
# imgHor = np.hstack((img, img))

# cv2.imshow('Horizontal', imgHor) 
# Similar goes for the verticals
cv2.waitKey(0)
