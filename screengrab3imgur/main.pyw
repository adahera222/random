import os
import hooks
import wx
from globals import globals


def main():
    homedir = os.path.expanduser('~')
    globals.ppath = os.path.join(homedir, 'AppData', 'Local', 'screengrab3imgur')
    globals.app = wx.App()
    globals.displays = (wx.Display(i) for i in range(wx.Display.GetCount()))
    globals.sizes = [display.GetGeometry() for display in globals.displays]
    globals.working = False 

    try:
        os.mkdir(globals.ppath)
    except OSError:
        pass

    hooks.Hooks()

if __name__ == "__main__":
    main()
