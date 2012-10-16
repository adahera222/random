import os
import eyeD3
import cPickle
from organize import *
from inverted import *

def getMP3Information(root, subdirs_format):
    """
    Runs organize.levelMP3Files() and then organize.organizeMP3Files().
    Returns a list of all MP3 files as MP3 objects.
    """

    organize.levelMP3Files(root)
    MP3_list = organize.organizeMP3Files(root, subdirs_format)

    return MP3_list


def getAllData(root, subdirs_format):
    """
    Fills the main data structure with all the information gathered by
    getMP3Information.

    Returns the MP3_list and the filled data. 
    The filled data IS the inverted index. All searches are performed using
    both the MP3_list and the inverted index.
    """

    fields = ['Artist', 'Album', 'Title', 'Genre', 'Year', 'Length', 'Bitrate']

    os.chdir(root)

    # Trying to load previously created information about the user's MP3s.
    try:
        MP3_list = loadData(root, "MP3_list")
    except IOError:
        MP3_list = getMP3Information(root, subdirs_format)
    else:
        organize.levelMP3Files(root)
        organize.organizeMP3Files(root, subdirs_format)

    # Only adds MP3s and saves them if data wasn't previously created.
    try:
        data = loadData(root, "data")
    except IOError:
        data = Data()
        
        for field in fields:
            for mp3 in MP3_list:
                data.addIL(eval("mp3." + field), field, MP3_list.index(mp3))

        saveData(root, MP3_list, "MP3_list")
        saveData(root, data, "data")

    return MP3_list, data


def saveData(root, data, filename):
    cPickle.dump(data, open(os.path.join(root, filename), 'wb'))


def loadData(root, filename):
    return cPickle.load(open(os.path.join(root, filename), 'rb'))


def flattenList(lOLn, level):
    for i in range(0,level):
        lOLn = [n for list_ in lOLn for n in list_]
    return lOLn


def removeDuplicates(list_):
    return list(set(list_))
