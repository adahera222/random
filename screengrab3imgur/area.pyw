import wx
import grab
import sys
from globals import globals

class Frame(wx.Frame):
    def __init__(self, width, height, x, y, i):
        style = (wx.STAY_ON_TOP | wx.NO_BORDER | wx.FRAME_NO_TASKBAR)
        wx.Frame.__init__(self, None, style=style, size=(width, height), pos=(x, y))
        self.SetTransparent(1)

        self.panel = wx.Panel(self, pos=(x, y), size=(width, height))
        self.panel.Bind(wx.EVT_MOTION, self.onMouseMove)
        self.panel.Bind(wx.EVT_LEFT_DOWN, self.onMouseDown)
        self.panel.Bind(wx.EVT_LEFT_UP, self.onMouseUp)
        # self.panel.Bind(wx.EVT_PAINT, self.onPaint)
        self.panel.Bind(wx.EVT_CLOSE, self.onClose)

        self.SetCursor(wx.StockCursor(wx.CURSOR_CROSS))

        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.i = i

        self.left_down = False

        # Initial and final positions - mouse left down and mouse left up.
        self.ci = None
        self.cf = None
        self.mx = 0
        self.my = 0
        self.pix = 0
        self.piy = 0
        self.pfx = 0
        self.pfy = 0

        # Screen boundaries: (x1, y1, x2, y2)
        self.bounds = (x, y, x + width, y + height)

        self.onTimer()

    def InBounds(self, x, y):
        if (x >= self.bounds[0] and y >= self.bounds[1] and 
            x <= self.bounds[2] and y <= self.bounds[3]):
            return True
        else: return False 

    def ClampPointer(self, x, y):
        if x <= self.bounds[0]: self.WarpPointer(self.x, y)
        elif x >= self.bounds[2]: self.WarpPointer(self.x + self.width, y)
        if y <= self.bounds[1]: self.WarpPointer(x, self.y)
        elif y >= self.bounds[3]: self.WarpPointer(x, self.y + self.height)

    def onTimer(self):
        self.mx, self.my = wx.GetMousePosition()

        """
        if self.InBounds(self.mx, self.my) == False:
            self.ClampPointer(self.mx, self.my)
        """

        wx.CallLater(1, self.onTimer)

    def onMouseMove(self, event):
        if event.LeftIsDown():
            self.cf = event.GetPosition()
            self.pfx, self.pfy = wx.GetMousePosition()
            self.Refresh()

    def onMouseDown(self, event):
        self.ci = event.GetPosition()
        self.pix, self.piy = wx.GetMousePosition()
        self.left_down = True

    def onMouseUp(self, event):
        self.cf = event.GetPosition()
        self.left_down = False
        self.pfx, self.pfy = wx.GetMousePosition()
        globals.rectangle = (self.pix, self.piy, self.pfx, self.pfy)
        grab.grab()
        self.Close(True)

    """
    def onPaint(self, event):
        if self.ci is None or self.cf is None: return
        
        dc = wx.PaintDC(self.panel)
        dc.SetPen(wx.Pen('black', 1))
        dc.SetBrush(wx.Brush('grey'))
        dc.DrawRectangle(self.pix, self.piy, self.pfx - self.pix, self.pfy - self.piy)
    """

    def onClose(self, event):
        wx.Stop()
        self.Destroy()
        return True

def run():
    frames = [Frame(globals.sizes[i].width, globals.sizes[i].height, globals.sizes[i].x, globals.sizes[i].y, i) for i in range(len(globals.sizes))]

    for frame in frames:
        frame.Show()

    globals.app.MainLoop()
