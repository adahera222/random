from organize import *
from search import *
from config import *

search_fields = []
MP3_list, data = [], []
refined = []

def setFieldList(widget, field):
    """
    search_fields holds all fields to be used in a search.
    It starts empty an as the user clicks the check button,
    fields will be added to it or removed from it.
    """

    if field in search_fields:
        search_fields.remove(field)
    else:
        search_fields.append(field)


def organizePath(widget, root):
    global MP3_list, data
    config_lists = config.configure(root)
    MP3_list, data = searchutils.getAllData(root, config_lists[0])


def searchMP3s(widget, string, text_buffer):
    """
    Searches for all MP3s that match string in MP3_list.
    Add information about the songs matched to the interfaces' text_buffer.
    """
    
    # List used for the function searchMP3Refine.
    # It simply stores MP3_list_positions from the last search.
    global refined

    # Deletes information from possible previous searches.
    start_iter = text_buffer.get_start_iter()
    end_iter = text_buffer.get_end_iter()
    text_buffer.delete(start_iter, end_iter)

    # Finds all positions in MP3_list that correspond to the current search.
    MP3_list_positions = data.search(string, search_fields)
    MP3_list_positions = searchutils.flattenList(MP3_list_positions, 1)
    MP3_list_positions = searchutils.removeDuplicates(MP3_list_positions)
    refined = MP3_list_positions

    # Adds information about all songs found.
    for i in range(0,len(MP3_list_positions)):
        mp3 = MP3_list[MP3_list_positions[i]]
        text_buffer_string = mp3.Artist + ' - ' + mp3.Title + ' (' + mp3.Length + ')\n'
        text_buffer.insert(text_buffer.get_iter_at_line(i+1), text_buffer_string)


def searchMP3Refine(widget, string, text_buffer):
    """
    Searches for all MP3s that match string in MP3_refined_list.
    MP3_refined_list is defined by creating a new Data and adding
    to it the MP3s in MP3_list with index defined by refined.
    """

    global refined
    fields = ['Artist', 'Album', 'Title', 'Genre', 'Year', 'Length', 'Bitrate']
    
    # Defines a new MP3_list by taking only the elements
    # found in the last search (those were stored in refined).
    MP3_refined_list = [MP3_list[n] for n in refined]

    new_data = inverted.Data()
    # Creates a new Data so we can search again.
    for field in fields:
        for mp3 in MP3_refined_list:
            new_data.addIL(eval("mp3." + field), field, MP3_refined_list.index(mp3))

    # Deletes information from possible previous searches.
    start_iter = text_buffer.get_start_iter()
    end_iter = text_buffer.get_end_iter()
    text_buffer.delete(start_iter, end_iter)

    # Finds all positions in MP3_list that correspond to the current search.
    MP3_refined_list_positions = new_data.search(string, search_fields)
    MP3_refined_list_positions = searchutils.flattenList(MP3_refined_list_positions, 1)
    MP3_refined_list_positions = searchutils.removeDuplicates(MP3_refined_list_positions)
    refined = MP3_refined_list_positions

    # Adds information about all songs found.
    for i in range(0,len(MP3_refined_list_positions)):
        mp3 = MP3_refined_list[MP3_refined_list_positions[i]]
        text_buffer_string = mp3.Artist + ' - ' + mp3.Title + ' (' + mp3.Length + ')\n'
        text_buffer.insert(text_buffer.get_iter_at_line(i+1), text_buffer_string)





