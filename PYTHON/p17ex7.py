#renaming text file
import os
oldname = "this.txt"
# newname="that.txt"
with open(oldname) as f:
    content = f.read()
with open("that.txt",'w') as f:
    f.write(content)
os.remove(oldname)
#will give error now as this.txt file has been removed from the directory