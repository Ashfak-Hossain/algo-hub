import subprocess
import os

# The path of sublime packages folder for manage snippets, build files etc...
path = "/Users/ashfakhossainevan/Library/Application Support/Sublime Text/Packages"
if os.path.exists(path):
    subprocess.run(["code", path])
else:
    print("Path does not exist!")