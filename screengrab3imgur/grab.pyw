import sys, os
import upload
import threading
import win32api, win32con
import Image
from PyQt4.QtGui import QPixmap, QApplication
from globals import globals

def grab():

    """
    # Grab screen
    hwin = win32gui.GetDesktopWindow()
    left = win32api.GetSystemMetrics(win32con.SM_XVIRTUALSCREEN)
    top = win32api.GetSystemMetrics(win32con.SM_YVIRTUALSCREEN)
    width = win32api.GetSystemMetrics(win32con.SM_CXVIRTUALSCREEN)
    height = win32api.GetSystemMetrics(win32con.SM_CYVIRTUALSCREEN)
    hwindc = win32gui.GetWindowDC(hwin)

    if globals.areaSelect == True:
        srcdc = win32ui.CreateDCFromHandle(hwindc)
        memdc = srcdc.CreateCompatibleDC()
        bmp = win32ui.CreateBitmap()
        bmp.CreateCompatibleBitmap(srcdc, (globals.rectangle[2] - globals.rectangle[0]), (globals.rectangle[3] - globals.rectangle[1]))
        memdc.SelectObject(bmp)
        memdc.BitBlt((0, 0), ((globals.rectangle[2] - globals.rectangle[0]), (globals.rectangle[3] - globals.rectangle[1])), srcdc, (globals.rectangle[0], globals.rectangle[1]), win32con.SRCCOPY)

    elif globals.areaSelect == False:
        srcdc = win32ui.CreateDCFromHandle(hwindc)
        memdc = srcdc.CreateCompatibleDC()
        bmp = win32ui.CreateBitmap()
        bmp.CreateCompatibleBitmap(srcdc, width, height)
        memdc.SelectObject(bmp)
        memdc.BitBlt((0, 0), (width, height), srcdc, (left, top), win32con.SRCCOPY) 

    bmp.SaveBitmapFile(memdc, os.path.join(globals.ppath, 's.bmp'))


    # Convert to PNG
    im = Image.open(os.path.join(globals.ppath, 's.bmp'))
    im.save(os.path.join(globals.ppath, 's.png') , 'PNG')

    # Remove BMP
    os.remove(os.path.join(globals.ppath, 's.bmp'))

    # Upload
    t = upload.UploadThread()
    t.start()
    """

    """
    dll = ctypes.WinDLL('gdi32.dll')
    for idx, (hMon, hDC, (left, top, right, bottom)) in enumerate(win32api.EnumDisplayMonitors(None, None)):
        hDeskDC = win32gui.CreateDC(win32api.GetMonitorInfo(hMon)['Device'], None, None)
        bitmap = wx.EmptyBitmap(right - left, bottom - top)
        hMemDC = wx.MemoryDC()
        hMemDC.SelectObject(bitmap)
        try:
            dll.BitBlt(hMemDC.GetHDC(), 0, 0, right - left, bottom - top, int(hDeskDC), 0, 0, win32con.SRCCOPY)
        finally:
            hMemDC.SelectObject(wx.NullBitmap)
        bitmap.SaveFile(os.path.join(globals.ppath, 's.bmp'), wx.BITMAP_TYPE_BMP)
        win32gui.ReleaseDC(win32gui.GetDesktopWindow(), hDeskDC)
    """

    left = win32api.GetSystemMetrics(win32con.SM_XVIRTUALSCREEN)
    top = win32api.GetSystemMetrics(win32con.SM_YVIRTUALSCREEN)
    width = win32api.GetSystemMetrics(win32con.SM_CXVIRTUALSCREEN)
    height = win32api.GetSystemMetrics(win32con.SM_CYVIRTUALSCREEN)
    app = QApplication(sys.argv)
    QPixmap.grabWindow(QApplication.desktop().winId(), left, top, width, height).save(os.path.join(globals.ppath, 's.png'), 'png')

    if globals.rectangle[0] != globals.rectangle[2] and globals.rectangle[1] != globals.rectangle[3]:
        if globals.areaSelect == True:
            im = Image.open(os.path.join(globals.ppath, 's.png'))
            if left < 0:
                im.crop((globals.rectangle[0] - left, globals.rectangle[1], globals.rectangle[2] - left, globals.rectangle[3])).save(os.path.join(globals.ppath, 's.png'), 'PNG')
            elif left >= 0:
                im.crop((globals.rectangle[0], globals.rectangle[1], globals.rectangle[2], globals.rectangle[3])).save(os.path.join(globals.ppath, 's.png'), 'PNG')

    globals.working = False
