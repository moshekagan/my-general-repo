# import os.path, time
# ff = '/Users/moshek/Documents/MyPictures/roni/jpeg/DSC_0176.JPG'
# f = open('/Users/moshek/Documents/MyPictures/roni/jpeg/DSC_0176.JPG')
# data = f.read()
# f.close()
# print "last modified: %s" % time.ctime(os.path.getmtime(ff))
# print "created : %s" % time.ctime(os.path.getctime(ff))


#!/usr/bin/env python
from stat import S_ISREG, ST_CTIME, ST_MODE
import os, sys, time
import datetime

def makeDirIfNotExsist(directory):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)
            print "New directory created: " + directory
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise

# path to the directory (relative or absolute)
dirpath = sys.argv[1] if len(sys.argv) == 2 else r'.'

# get all entries in the directory w/ stats
entries = (os.path.join(dirpath, fn) for fn in os.listdir(dirpath))
entries = ((os.stat(path), path) for path in entries)

# leave only regular files, insert creation date
# entries = ((stat[ST_CTIME], path)
entries = ((stat.st_birthtime, path)
           for stat, path in entries if S_ISREG(stat[ST_MODE]))
# NOTE: on Windows `ST_CTIME` is a creation date
#  but on Unix it could be something else
# NOTE: use `ST_MTIME` to sort by a modification date

for cdate, path in sorted(entries):    # print time.ctime(cdate), os.path.basename(path)
    creationDate = datetime.datetime.strptime(time.ctime(cdate), "%a %b %d %H:%M:%S %Y").date()
    print creationDate, path
    newDirctoryPath = dirpath + str(creationDate)
    print dirpath
    print newDirctoryPath
    makeDirIfNotExsist(newDirctoryPath)

    newFile = os.path.join(newDirctoryPath, os.path.basename(path))
    print("Moving " + path + " to " + newFile)
    os.rename(path, newFile)
