from PIL import Image
import sys

input1 = sys.argv[1]
input2 = sys.argv[2]
output = sys.argv[3]

img1 = Image.open(input1)
img2 = Image.open(input2)

width1, height1 = img1.size

width2, height2 = img2.size

x = (width1 - width2) // 2
y = (height1 - height2) // 2

result = Image.new("RGB", (width1, height1), "white")
result.paste(img1, (0, 0))

result.paste(img2, (x, y))

result.save(output)
