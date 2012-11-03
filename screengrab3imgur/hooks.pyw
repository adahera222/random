import pythoncom, pyHook
import sys
import area, grab
from globals import globals

def OnKeyboardEvent(event):
    """
    print 'MessageName:',event.MessageName
    print 'Message:',event.Message
    print 'ASCII:',event.Ascii, chr(event.Ascii)
    print 'Key:',event.Key
    print 'KeyID',event.KeyID
    print 'ScanCode:',event.ScanCode
    print 'Alt',event.Alt
    print '---'
    """

    if globals.working == False:
        ctrl_pressed = pyHook.GetKeyState(162)
        if ctrl_pressed and pyHook.HookConstants.IDToName(event.KeyID) == 'Snapshot':
            globals.areaSelect = False
            globals.working = True
            grab.grab()

        elif event.Key == 'Snapshot':
            globals.areaSelect = True
            globals.working = True
            area.run()

    return True

def Hooks():
    hm = pyHook.HookManager()
    hm.KeyDown = OnKeyboardEvent
    hm.HookKeyboard()
    pythoncom.PumpMessages()
