import os


class MP3:
    def __init__(self, Length, Title, Artist, Album,
                 Genre, Year, Bitrate, Filename):
        self.Length = Length
        self.Title = Title
        self.Artist = Artist
        self.Album = Album
        self.Genre = Genre
        self.Year = Year
        self.Bitrate = Bitrate
        self.Filename = Filename 
        self.Path = ""


    def setPath(self, directory):
        self.Path = os.path.join(directory, self.Filename)
