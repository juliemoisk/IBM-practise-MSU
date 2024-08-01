import os
import numpy as np
import imageio
import sys

input1 = sys.argv[1]
input2 = sys.argv[2]
output = sys.argv[3]

img1 = imageio.v2.imread(input1)
img2 = imageio.v2.imread(input2)

height1, width1, channels1 = img1.shape
height2, width2, channels2 = img2.shape

x_offset = (width1 - width2) // 2
y_offset = (height1 - height2) // 2

new_img = np.zeros_like(img1)
new_img[:height1, :width1, :] = img1

new_img[y_offset:y_offset+height2, x_offset:x_offset+width2, :] = img2

imageio.imsave(output, new_img)
