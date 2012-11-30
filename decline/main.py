#!/usr/bin/env python
# -*- coding: utf8 -*-

import string, os
from datetime import datetime

# This is a list of tuples with the format:
# (day, time, person, [message])
messages = [] 

# This is a list of sections:
# A section is defined by the set of messages that happen
# without n hours stops between them. So if 45 consecutive 
# messages happen with the interval between each message
# being < n hours, all those belong to one section. A section
# will be a tuple with the start/end interval: (start, end)
sections = []
section_counter = 0
section_seconds = 3600 # 1 hour defines a section

def main():
    global messages
    global sections
    global section_counter

    homedir = os.path.expanduser('~')
    f = open(os.path.join(homedir, 'Desktop', 'tsg.txt'), 'r')
    lines = f.readlines()
    lines = map(lambda line: line.strip(), lines)
    lines = map(lambda line: ''.join(filter(lambda x: x in string.printable, line)), lines)

    for line in lines:
        if line:
            day, time = getDayAndTimeFromLine(line)
            person = getPersonFromLine(line)
            message = getMessageFromLine(line)
            addMessageToDict(day, time, person, message)

    f.close()

    findSections()
    print section_counter

def findSections():
    global messages
    global sections
    global section_seconds
    global section_counter

    # Initialize first section's start
    sections.append((0, None))

    for i in range(0, len(messages)): 
        # Since we'll always check the difference in time between
        # i and i+1, ensure we never go out of the array's bounds
        if i <= len(messages)-2:
            dt = diffTime(messages[i][1], messages[i+1][1])
            if dt > section_seconds:
                # Set current section's end
                current_tuple_list = list(sections[section_counter])
                current_tuple_list[1] = i
                sections[section_counter] = tuple(current_tuple_list)
                section_counter += 1
                # Set next section's start
                sections.append((i+1, None))

def diffTime(time1, time2):
    delta = datetime.strptime(time2, '%H:%M:%S') - datetime.strptime(time1, '%H:%M:%S')
    return delta.seconds

def addMessageToDict(day, time, person, message):
    global messages
    new_tuple = (day, time, person, [message])

    if day == None and time == None and person == None:
        messages[-1][3].append(message)
    else:
        messages.append(new_tuple)

def getDayAndTimeFromLine(line):
    if line[0] == '[' and line[3] == '/' and line[20] == ']':
        return line[1:11], line[12:20]
    else:
        return None, None

def getPersonFromLine(line):
    if line[0] == '[' and line[3] == '/' and line[20] == ']':
        return line[22:line.find(':', 22, line.__len__())]
    else:
        return None

def getMessageFromLine(line):
    if line[0] == '[' and line[3] == '/' and line[20] == ']':
        return line[line.find(':', 22, line.__len__())+2:]
    else: 
        return line

if __name__ == '__main__':
    main()
