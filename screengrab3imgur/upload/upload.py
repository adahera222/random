import pycurl
from xml.dom import minidom
import cStringIO
import sys
import pyperclip

def upload():
    c = pycurl.Curl()
    response = cStringIO.StringIO()

    params = [
        ("key", "8401d86c15b5aa70dd60f38ed6165fce"),
        ("image", (c.FORM_FILE, sys.argv[1]))
    ]

    c.setopt(c.URL, "http://api.imgur.com/2/upload.xml")
    c.setopt(c.HTTPPOST, params)
    c.setopt(c.WRITEFUNCTION, response.write)
    c.perform()
    c.close()

    imageURL = "" 
    error = ""

    try:
        xml = minidom.parseString(response.getvalue())
        imageURL = xml.getElementsByTagName("original")[0].firstChild.data

    except:
        error = "Problem uploading."

    pyperclip.copy(imageURL)

    print imageURL
    print error

    return imageURL, error

if __name__ == '__main__':
    upload()

