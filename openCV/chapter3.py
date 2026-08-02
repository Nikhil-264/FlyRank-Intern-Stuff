import cv2
img = cv2.imread("Resources/misti.png")

# print(img.shape)

width = int(img.shape[1] * 30 / 100)
height = int(img.shape[0] * 30 / 100)
dim = (width, height)

img_resized = cv2.resize(img, dim) # can be used for cropping
print(img_resized.shape)

imgCropped = img_resized[20:460, 20:460] # cropped image based on the size of the original image
cv2.imshow("image", imgCropped)
cv2.imshow("image2", img_resized)

cv2.waitKey(0)