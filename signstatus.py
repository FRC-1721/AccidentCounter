import urwid, time

class Main(object):
    def __init__(self):
        self.failflip = False
        self.passflip = False

        palette = [
            ('banner', 'black', 'light gray'),
            ('fail', 'black', 'dark red'),
            ('pass', 'black', 'dark green'),]

        title = urwid.BigText('Vestabot.service', urwid.HalfBlock5x4Font())
        title = urwid.Padding(title, 'center', None)
        title = urwid.Filler(title, 'middle', None, 7)

        txt = urwid.Text(('banner', u" Theres no text for this particular test.\nBut check back later when im all configured!\nI'll display live stats, just you wait! "), align='center') 
        txt = urwid.Filler(txt, 'middle')

        titletext = urwid.Pile([title, txt])
        titletext = urwid.LineBox(titletext)


        list = urwid.SimpleFocusListWalker([urwid.Text("This service has no test cases!", align='center'), urwid.Text("This service has broken test cases, lol joe u need to fill this in", align='center')])
        list = urwid.ListBox(list)
        list = urwid.AttrMap(list, 'fail')
        list = urwid.LineBox(list)

        topcol = urwid.Columns([titletext, list])



        bt = urwid.BigText('code bjorked', urwid.HalfBlock7x7Font())
        bt = urwid.Padding(bt, 'center', None)
        bt = urwid.Filler(bt, 'middle', None, 7)
        bt = urwid.AttrMap(bt, 'fail')
        bt = urwid.LineBox(bt)

        pile = urwid.Pile([bt])

        self.loop = urwid.MainLoop(pile, palette)

        self.loop.set_alarm_at(time.time() + 1, self.failflash)
        self.loop.set_alarm_at(time.time() + 1, self.passflash)
        self.loop.run()

    def failflash(self, data, userdata):
        self.failflip = not self.failflip
        self.loop.screen.register_palette_entry('fail', ['black', 'dark red'][self.failflip], ['dark red', 'black'][self.failflip])
        self.loop.screen.clear()

        self.loop.set_alarm_at(time.time() + 1, self.failflash)

    def passflash(self, data, userdata):
        self.passflip = not self.passflip
        self.loop.screen.register_palette_entry('pass', ['dark green', 'black'][self.passflip], 'dark green')
        self.loop.screen.clear()

        if self.passflip:
            self.loop.set_alarm_at(time.time() + 0.7, self.passflash)
        else:
            self.loop.set_alarm_at(time.time() + 0.2, self.passflash)

Main()
