import pycurl
from xml.dom import minidom
import cStringIO
import sys, os
import pyperclip
from globals import globals
import threading

class UploadThread(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        c = pycurl.Curl()
        response = cStringIO.StringIO()

        key_file = open(os.path.join(globals.ppath, 'key.txt'), 'r')
        key = key_file.readline().rstrip()

        params = [
            ("key", key),
            ("image", (c.FORM_FILE, os.path.join(globals.ppath, 's.png')))
        ]

        c.setopt(c.URL, "http://api.imgur.com/2/upload.xml")
        c.setopt(c.HTTPPOST, params)
        c.setopt(c.WRITEFUNCTION, response.write)
        c.setopt(c.CONNECTTIMEOUT, 60)
        c.setopt(c.TIMEOUT, 120)
        c.perform()
        c.close()

        imageURL = "" 
        error = ""

        try:
            xml = minidom.parseString(response.getvalue())
            imageURL = xml.getElementsByTagName("original")[0].firstChild.data

        except:
            error = "Problem uploading."

        if not error:
            pyperclip.copy(imageURL)
        else:
            pyperclip.copy(error)

        globals.working = False
