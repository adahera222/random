#!/usr/bin/env python
# -*- coding: utf8 -*-

import string, os

def main():
    homedir = os.path.expanduser('~')
    f = open(os.path.join(homedir, 'Desktop', 'tsg.txt'), 'r')
    lines = f.readlines()
    lines = map(lambda line: line.strip(), lines)
    lines = map(lambda line: ''.join(filter(lambda x: x in string.printable, line)), lines)
    print getDayAndTimeFromLine(lines[10005])
    print getPersonFromLine(lines[10005])
    print getMessageFromLine(lines[10005])
    f.close()

def getDayAndTimeFromLine(line):
    return line[1:11], line[12:20]

def getPersonFromLine(line):
    return line[22:line.find(':', 22, line.__len__())]

def getMessageFromLine(line):
    return line[line.find(':', 22, line.__len__())+2:]

if __name__ == '__main__':
    main()
