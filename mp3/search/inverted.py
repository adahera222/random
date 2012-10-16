import re


class InvertedList:
    """
    This class contains information about the MP3 objects
    retrieved by getMP3Information().

    Example:
        MP3_list = [MP31, MP32, MP33], where:
        MP31.Artist = 'Camel'
        MP31.Album = 'Camel'
        MP31.Title = 'Slow Yourself Down'
        MP32.Artist = 'Perfume'
        MP32.Album = 'Computer City'
        MP32.Title = 'Perfume'
        MP33.Artist = 'Camel'
        MP33.Album = 'Camel'
        MP33.Title = 'Six Ate'

        For each MP3 attribute, an instance of this class
        is created: 
            Artist_list = InvertedList()
            Album_list = InvertedList()
            Title_list = InvertedList()

        For each MP3 object in MP3_list and for each Inverted
        list, they are changed as follows:
            Artist_list.Field.append(MP3x.Artist)
            Of course, if MP3x.Artist already is in the Field
            list, then doing that is unnecessary.

            Artist_list.Postings.append([x])
            Simply add the position of this Artist as seen on
            MP3_list (the position must be added as a list).

        Artist_list = Inverted()
        Artist_list.Field.append('Camel')
        Artist_list.Postings.append([0])
        Artist_list.Field.append('Perfume')
        Artist_list.Postings.append([1])
        Since the third element is already in the list, add it's
        MP3_list position to the previously created 'Camel' list.
        Artist_list.Postings[0].append(2)

        After that, search based on the artist name is easy: 
        simply check if Artist_list.Field has the artist, if it does,
        store its position in x, then Artist_list.Postings[x]
        has all positions of this artist in MP3_list. 
    """

    def __init__(self):
        self.Field = []
        self.Postings = []


    def addField(self, string):
        """
        Returns True if the string was added to the Field list.
        Returns False if the string was already in the Field list.
        """

        if not string in self.Field:
            self.Field.append(string)
            return True
        return False

    
    def getFieldPosition(self, string):
        """ Returns the first position found that match string. """
        return self.Field.index(string)


class Data(InvertedList):
    def __init__(self):
        self.Artist = InvertedList()
        self.Title = InvertedList()
        self.Album = InvertedList()
        self.Genre = InvertedList()
        self.Year = InvertedList()
        self.Length = InvertedList()
        self.Bitrate = InvertedList()


    def addIL(self, string, field, index):
        """
        field:String, index:Number
        Adds string to self.field. Uses InvertedList.addField(string)
        Adds MP3_list position to InvertedList.Postings using index.

        TODO: try to do this without using eval? Not sure if setattr 
        will work here...
        """

        if eval("self." + field + ".addField(string)") == False:
            # Using the example defined in InvertedList:
            # If 'Camel' was already in the Field list, then
            # get its position in Field and index in MP3_list position
            # and add it to the Postings list.
            position = eval("self." + field + ".getFieldPosition(string)")
            eval("self." + field + ".Postings[position].append(index)") 
        else:
            # Else, 'Camel' was not in the Field list, then
            # simply add it and add the index as a list to the
            # Postings list.
            eval("self." + field + ".addField(string)")
            eval("self." + field + ".Postings.append([index])")


    def search(self, string, field_list):
        """
        field_list:StringList
        Searches through the Data structure for a given string.

        For all fields in field_list, if the string matches any 
        of the strings in self.field.Field, then position = 
        self.field.getFieldPosition(string).

        Returns a list of self.field.Postings[position] for all
        searched elements (a list of lists).
        
        Using the example defined in InvertedList:
        If string = 'S' and field_list = ['Title'], we should expect
        positions 0 and 2 to be returned. What this function returns:
        MP3_list_positions = [[0,2], [0,2]]
        This happens because for each element found, the Postings 
        list will be added. Post-processing should be done so that 
        MP3_list_positions = [0, 2]
        """

        # MP3_list_positions:NumberListList -> Contains a list of lists
        # of numbers. Those numbers represent the position of the MP3
        # searched in MP3_list. 
        MP3_list_positions = []

        for field in field_list:
            for element in eval("self." + field + ".Field"):
                if re.search(string, element) != None:
                    position = eval("self." + field + ".getFieldPosition(element)")
                    MP3_list_positions.append(eval("self." + field + ".Postings[position]"))

        return MP3_list_positions
