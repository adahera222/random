import os
import shutil
import eyeD3
from mp3 import *


# UTF-8 encoding used on all strings to support non-ASCII
# directory and file names.


def getMP3Files(directory):
    try:
        files = os.listdir(directory.decode("utf-8"))    
    except UnicodeEncodeError:
        files = os.listdir(directory)

    # MP3_files:StringList -> Contains all MP3 files from 
    # the directory path.
    MP3_files = filter(eyeD3.isMp3File, files)

    return MP3_files


def getSubdirs(directory):
    try:
        files = os.listdir(directory.decode("utf-8"))
    except UnicodeEncodeError:
        files = os.listdir(directory)

    # subdirs:StringList -> Contains all subdirectories 
    # from the directory path.
    subdirs = filter(os.path.isdir, files)

    return subdirs


def levelMP3Files(root):  
    """
    Brings all files on subdirectories to the current working directory.

    Also deletes all existing directories.
    This means that ALL files contained that are NOT
    of the MP3 extension will be deleted.

    TODO: find a way to link existing files that aren't MP3s to their
    respective group of MP3s. This way files that belong to an album,
    for instance, won't be deleted.
    """
    
    # Walks through all subdirectories and moves all MP3 
    # files to the root directory.
    for path, folder, files in os.walk(root.decode("utf-8")):
        MP3_files = getMP3Files(path)
        for MP3 in MP3_files:
            if path != root:
                shutil.move(os.path.join(path, MP3), root)

    # Removes all subdirectories from the root directory.
    subdirs = getSubdirs(root)
    for subdir in subdirs:
        shutil.rmtree(subdir)


def getMetadata(tag, trackInfo, MP3_file):
    """
    Creates and returns an object created with the
    information from a previously created and linked tag.
    """

    # Gathers all the metadata information and creates a 
    # new object of the class MP3.

    try:
        Artist = tag.getArtist().decode("utf-8")
    except UnicodeEncodeError:
        Artist = tag.getArtist()

    try:
        Album = tag.getAlbum().decode("utf-8")
    except UnicodeEncodeError:
        Album = tag.getAlbum()

    try:
        Title = tag.getTitle().decode("utf-8")
    except UnicodeEncodeError:
        Title = tag.getTitle()

    try:
        Genre = tag.getGenre().name.decode("utf-8")
    except UnicodeEncodeError:
        Genre = tag.getGenre().name
    except AttributeError:
        Genre = ""

    try:
        Year = tag.getYear().decode("utf-8")
    except AttributeError:
        Year = ""

    Length = trackInfo.getPlayTimeString()
    Bitrate = trackInfo.getBitRateString()

    MP3_obj = MP3(Length, Title, Artist, Album, Genre, Year, Bitrate, MP3_file)

    return MP3_obj


def createSubdirectories(MP3_obj, root, subdirs_format):
    """
    Creates appropriate directories for the MP3_obj
    according to the subdirs_format list of strings.

    Example:
        MP3_obj.Filename = "1.mp3"
        subdirs_format = ['Genre', 'Artist', 'Album']
        
        This should create 3 levels of directories,
        moving "1.mp3" to /Genre/Artist/Album/1.mp3,
        where Genre, Artist and Album are the respective
        informations from the MP3 file.

    Returns an updated object and changes the directories
    accordingly.
    """

    MP3_path = os.path.join(root, getattr(MP3_obj, 'Filename'))
    # String of paths created in the incoming loop.
    # Auxiliary use only.
    paths = []
    
    for subdir in subdirs_format: 
        attr = getattr(MP3_obj, subdir)
        if subdirs_format.index(subdir) == 0:
            paths.append(os.path.join(root, attr))
        else: 
        # Creates a new path based on the previous
        # path. To create /Genre/Artist you'd need
        # /Genre/, for example.
            paths.append(os.path.join(paths[-1], attr))
        
        if not os.path.exists(paths[-1]): os.mkdir(paths[-1])

    # After all paths have been created, sets the
    # proper path for the object and moves the file
    # to it's new location.
    MP3_obj.setPath(paths[-1])
    shutil.move(MP3_path, getattr(MP3_obj, 'Path')) 

    return MP3_obj

    
def organizeMP3Files(root, subdirs_format):
    """
    Creates appropriate directories to all MP3 files 
    according to their metadata.

    Should be run preferably after levelMP3Files(). 
    Returns a list with all the MP3 objects created.
    """

    MP3_files = getMP3Files(root)
    MP3_objects = []

    for MP3_file in MP3_files:

        # Path to the current MP3 file.
        MP3_path = os.path.join(root, MP3_file)

        # Links the current MP3 to an eyeD3 tag.
        trackInfo = eyeD3.Mp3AudioFile(MP3_path) 
        tag = trackInfo.getTag()
        tag.link(MP3_path)

        MP3_obj = getMetadata(tag, trackInfo, MP3_file)

        # Creates new paths according to the specified 
        # format for the current MP3.
        MP3_obj = createSubdirectories(MP3_obj, root, subdirs_format)  
        MP3_objects.append(MP3_obj)

    return MP3_objects
