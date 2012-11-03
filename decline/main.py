#!/usr/bin/env python
# -*- coding: utf8 -*-

import string, os

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
section_minutes = 60 # 1 hour defines a section

def main():
    global messages

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
            print day, time, timeToNumber(time)

    f.close()

'''
def findSections():
    global messages
    global sections
    global section_minutes


# Time format: 'hh/mm/ss'
def diffTime(time1, time2):
'''

def timeToNumber(time):
    if time:
        return int(time[0:2]), int(time[3:5]), int(time[6:8]) 
    else:
        return None, None, None

def getDayAndTimeFromLine(line):
    if line[0] == '[':
        return line[1:11], line[12:20]
    else:
        return None, None

def getPersonFromLine(line):
    if line[0] == '[':
        return line[22:line.find(':', 22, line.__len__())]
    else:
        return None

def getMessageFromLine(line):
    if line[0] == '[':
        return line[line.find(':', 22, line.__len__())+2:]
    else: 
        return line

def addMessageToDict(day, time, person, message):
    global messages
    new_tuple = (day, time, person, [message])

    if day == None and time == None and person == None:
        messages[-1][3].append(message)
    else:
        messages.append(new_tuple)

if __name__ == '__main__':
    main()
