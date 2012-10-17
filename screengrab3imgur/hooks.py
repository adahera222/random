import pythoncom, pyHook
import sys

def OnMouseEvent(event):
    print 'MessageName:',event.MessageName
    print 'Message:',event.Message
    print 'Position:',event.Position
    print 'Wheel:',event.Wheel
    print 'Injected:',event.Injected
    print '---'
    return True

def OnKeyboardEvent(event):
    print 'MessageName:',event.MessageName
    print 'Message:',event.Message
    print 'ASCII:',event.Ascii, chr(event.Ascii)
    print 'Key:',event.Key
    print '---'

    if event.Ascii == 113:
        sys.exit()

    return True

hm = pyHook.HookManager()
hm.MouseAll = OnMouseEvent
hm.HookMouse()
hm.KeyDown = OnKeyboardEvent
hm.HookKeyboard()
pythoncom.PumpMessages()
