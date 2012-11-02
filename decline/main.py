#!/usr/bin/env python
# -*- coding: utf8 -*-

import string

def main():
    f = open('/home/adn/decline/tsg.txt', 'r')
    lines = f.readlines()
    lines = map(lambda line: line.strip(), lines)
    lines = map(lambda line: ''.join(filter(lambda x: x in string.printable, line)), lines)
    getDayAndTimeFromLine(lines[1])
    f.close()

def getDayAndTimeFromLine(line):
    print line[1]

if __name__ == '__main__':
    main()
