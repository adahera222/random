import win32gui, win32ui, win32con, win32api
import Image
import sys, os

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
    bmp.CreateCompatibleBitmap(srcdc, width, height)
    memdc.SelectObject(bmp)
    memdc.BitBlt((0, 0), (width, height), srcdc, (left, top), win32con.SRCCOPY)
    bmp.SaveBitmapFile(memdc, os.path.join(sys.argv[1], 's.bmp'))

    # Convert to PNG
    im = Image.open(os.path.join(sys.argv[1], 's.bmp'))
    im.save(os.path.join(sys.argv[1], 's.png') , 'PNG')

    # Remove BMP
    os.remove(os.path.join(sys.argv[1], 's.bmp'))

if __name__ == "__main__":
    grab()
