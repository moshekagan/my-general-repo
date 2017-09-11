import os
import sys

def main():
    currentDirctory = getPathToDirectoryWithPhotos()
    validatePath(currentDirctory)

    desinationDirctoryRaw = currentDirctory + "/raw"
    desinationDirctoryJpeg = currentDirctory + "/jpeg"

    makeDirUnderThePath(desinationDirctoryRaw)
    makeDirUnderThePath(desinationDirctoryJpeg)

    moveFileWithExtentionToPath("JPG", currentDirctory, desinationDirctoryJpeg)
    moveFileWithExtentionToPath("NEF", currentDirctory, desinationDirctoryRaw)


def getPathToDirectoryWithPhotos():
    path = raw_input("Enter path to the directory with the photos: ")
    answer = query_yes_no("Are you sure this is the right path: " +  path + " ?")
    if answer == False:
        raise RuntimeError('User enter worng path...')

    return path


def validatePath(path):
    if not os.path.exists(path):
        raise RuntimeError('is invalide path! :(')


def makeDirUnderThePath(directory):
    try:
        os.makedirs(directory)
        print "New directory created: " + directory
    except OSError as e:
        if e.errno != errno.EEXIST:
            raise

def moveFileWithExtentionToPath(extention, currentDirctory, desinationDirctory):
    for file in os.listdir(currentDirctory):
        if file.endswith(extention):
            oldFile = os.path.join(currentDirctory, file)
            newFile = os.path.join(desinationDirctory, file)
            print("Moving " + oldFile + " to " + newFile)
            os.rename(oldFile, newFile)


def query_yes_no(question, default="yes"):
    """Ask a yes/no question via raw_input() and return their answer.

    "question" is a string that is presented to the user.
    "default" is the presumed answer if the user just hits <Enter>.
        It must be "yes" (the default), "no" or None (meaning
        an answer is required of the user).

    The "answer" return value is True for "yes" or False for "no".
    """
    valid = {"yes": True, "y": True, "ye": True,
             "no": False, "n": False}
    if default is None:
        prompt = " [y/n] "
    elif default == "yes":
        prompt = " [Y/n] "
    elif default == "no":
        prompt = " [y/N] "
    else:
        raise ValueError("invalid default answer: '%s'" % default)

    while True:
        sys.stdout.write(question + prompt)
        choice = raw_input().lower()
        if default is not None and choice == '':
            return valid[default]
        elif choice in valid:
            return valid[choice]
        else:
            sys.stdout.write("Please respond with 'yes' or 'no' "
                             "(or 'y' or 'n').\n")

try:
    main()
except RuntimeError, e:
    print "Oops! " + str(e)
