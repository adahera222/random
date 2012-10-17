import wx

class Frame(wx.Frame):
    def __init__(self, width, height, x, y, i):
        style = (wx.STAY_ON_TOP | wx.NO_BORDER | wx.FRAME_NO_TASKBAR)
        wx.Frame.__init__(self, None, style=style, size=(width, height), pos=(x, y))
        self.SetTransparent(55)
        self.i = i
        self.ix = 0
        self.iy = 0
        self.fx = 0
        self.fy = 0

        self.Bind(wx.EVT_LEFT_DOWN, self.on_left_down)
        self.Bind(wx.EVT_LEFT_UP, self.on_left_up)

        if self.i == 0:
            self.on_timer()

    def on_timer(self):
        mx, my = wx.GetMousePosition()
        # print mx, my
        wx.CallLater(20, self.on_timer)

    def on_left_down(self, event):
        self.ix, self.iy = wx.GetMousePosition()
        print self.ix, self.iy

    def on_left_up(self, event):
        self.fx, self.fy = wx.GetMousePosition()
        print self.fx, self.fy


if __name__ == '__main__':
    app = wx.App()

    displays = (wx.Display(i) for i in range(wx.Display.GetCount()))
    sizes = [display.GetGeometry() for display in displays]
    frames = (Frame(sizes[i].width, sizes[i].height, sizes[i].x, sizes[i].y, i) for i in range(len(sizes)))

    for frame in frames:
        frame.Show()

    app.MainLoop()
