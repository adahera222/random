import pythoncom, pyHook
import sys
import area
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

    if event.Ascii == 113: sys.exit()

    ctrl_pressed = pyHook.GetKeyState(162)

    if ctrl_pressed and pyHook.HookConstants.IDToName(event.KeyID) == 'Snapshot':
        area.run()

    return True

def Hooks():
    hm = pyHook.HookManager()
    hm.KeyDown = OnKeyboardEvent
    hm.HookKeyboard()
    pythoncom.PumpMessages()
