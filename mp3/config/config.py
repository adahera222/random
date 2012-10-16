import os

def configure(root):
    """
    Reads the configuration file and returns appropriate
    lists of lists containing information about each line.
    config_lists[0], for instance, is a list defining
    subdirectory format. For each line a new function is 
    defined so it can be parsed properly.
    """

    config_lists = []

    config_file = open(os.path.join(root, "conf"), 'rb')
    lines = config_file.readlines()

    # Removes commented lines (start with #).
    lines = filter(lambda x: x[0] != '#', lines)

    # First line: define subdirectory format.
    subdirs_format = getSubdirsFormat(lines[0]) 
    config_lists.append(subdirs_format)

    # Other lines' functions go here.

    return config_lists


def getSubdirsFormat(line):
    subdirs_format = []

    # Removes /n, CR...
    line = line.strip()

    last_backslash = 0
    while last_backslash != -1:
        current_backslash = line.find('/', last_backslash)

        # Sets the current backslash to None when EOF
        # has been reached. line[last_backslash:None] will
        # return the substring after last_backlash.
        if current_backslash == -1:
            current_backslash = None
        subdirs_format.append(line[last_backslash:current_backslash])

        # Sets last_backslash to -1 then exits the loop.
        if current_backslash == None:
            current_backslash = -2
        last_backslash = current_backslash + 1

    return subdirs_format
