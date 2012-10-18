import win32gui, win32ui, win32con, win32api
import Image
import sys, os
from globals import globals

def grab():

    # Grab screen
    hwin = win32gui.GetDesktopWindow()
    width = win32api.GetSystemMetrics(win32con.SM_CXVIRTUALSCREEN)
    height = win32api.GetSystemMetrics(win32con.SM_CYVIRTUALSCREEN)
    left = win32api.GetSystemMetrics(win32con.SM_XVIRTUALSCREEN)
    top = win32api.GetSystemMetrics(win32con.SM_YVIRTUALSCREEN)
    hwindc = win32gui.GetWindowDC(hwin)
    srcdc = win32ui.CreateDCFromHandle(hwindc)
    memdc = srcdc.CreateCompatibleDC()
    bmp = win32ui.CreateBitmap()
    bmp.CreateCompatibleBitmap(srcdc, (globals.rectangle[2] - globals.rectangle[0]), (globals.rectangle[3] - globals.rectangle[1]))
    memdc.SelectObject(bmp)
    memdc.BitBlt((0, 0), ((globals.rectangle[2] - globals.rectangle[0]), (globals.rectangle[3] - globals.rectangle[1])), srcdc, (globals.rectangle[0], globals.rectangle[1]), win32con.SRCCOPY)
    bmp.SaveBitmapFile(memdc, os.path.join(globals.ppath, 's.bmp'))

    # Convert to PNG
    im = Image.open(os.path.join(globals.ppath, 's.bmp'))
    im.save(os.path.join(globals.ppath, 's.png') , 'PNG')

    # Remove BMP
    os.remove(os.path.join(globals.ppath, 's.bmp'))
