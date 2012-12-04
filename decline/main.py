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

# Most stable (with less nickname changes) person
main_person = []

# Positions where messages change from being continuous from one person
flips = []

def main():
    global messages
    global sections
    global section_counter
    global main_person
    global flips

    homedir = os.path.expanduser('~')
    f = open(os.path.join(homedir, 'Desktop', 'ell.txt'), 'r')
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

    p = open(os.path.join(homedir, 'Desktop', 'ell_person.txt'), 'r')
    lines = p.readlines()
    lines = map(lambda line: line.strip(), lines)
    for line in lines:
        main_person.append(line)
    p.close()

    # 1: number of messages per person
    # print nMessagesPerPerson()

    findSections()

    # 2: number of sections started per person
    # print nSectionsStartedPerPerson()

    findFlips()

    # 3: average response time per person
    # print averageResponseTimePerPerson()

def averageResponseTimePerPerson():
    global messages
    global flips

    main_person_counter = 0
    main_person_sum = 0
    other_person_counter = 0
    other_person_sum = 0

    for flip in flips:
        if not startOrEndSectionMessage(flip[0], flip[1]):
            first_message = messages[flip[0]]
            second_message = messages[flip[1]]
            dt = diffTime(first_message[1], second_message[1])
            if equalsMainPerson(first_message):
                main_person_counter += 1
                main_person_sum += dt
            else:
                other_person_counter += 1
                other_person_sum += dt
    return main_person_sum/main_person_counter, other_person_sum/other_person_counter

def startOrEndSectionMessage(start, end):
    global messages
    global sections

    for section in sections:
        if section[0] == start or section[0] == end or \
           section[1] == start or section[1] == end:
            return True
    return False

def findFlips():
    global messages
    global flips

    for i in range(0, len(messages)):
        if i <= len(messages)-2:
            if messages[i][2] != messages[i+1][2]:
                flips.append((i, i+1))

def nSectionsStartedPerPerson():
    global sections
    global messages

    main_person_counter = 0
    other_person_counter = 0

    for section in sections:
        if equalsMainPerson(messages[section[0]]):
            main_person_counter += 1
        else:
            other_person_counter += 1
    return main_person_counter, other_person_counter

def nMessagesPerPerson():
    global main_person

    main_person_counter = 0
    other_person_counter = 0

    for message in messages:
        if equalsMainPerson(message):
            main_person_counter += 1
        else:
            other_person_counter += 1
    return main_person_counter, other_person_counter

def equalsMainPerson(message):
    global main_person

    for name in main_person:
        if name == message[2]:
            return True 
    return False

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
                # Set next section's start
                section_counter += 1
                sections.append((i+1, None))
    final_tuple = list(sections[-1])
    final_tuple[1] = len(messages)
    sections[-1] = tuple(final_tuple)

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
