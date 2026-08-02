import nibabel as nib
import matplotlib.pyplot as plt

path = r"E:\4th year\Sem 8\BTP-2\BraTS2020_TrainingData\MICCAI_BraTS2020_TrainingData\BraTS20_Training_001\BraTS20_Training_001_t1.nii"

img = nib.load(path)
data = img.get_fdata()

plt.imshow(data[:, :, 70], cmap="gray")
plt.axis("off")
plt.show()