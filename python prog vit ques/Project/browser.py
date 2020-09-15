import webkit
import gtk

#WOW
class Doge():

    def __init__(self):
        # Create window
        self.much_window = gtk.Window()
        self.much_window.set_icon_from_file('doge.png')
        self.much_window.connect('destroy', lambda w: gtk.main_quit())
        self.much_window.set_default_size(360, 600)

        # Create navigation bar
        self.so_navigation = gtk.HBox()

        self.many_back = gtk.ToolButton(gtk.STOCK_GO_BACK)
        self.such_forward = gtk.ToolButton(gtk.STOCK_GO_FORWARD)
        self.very_refresh = gtk.ToolButton(gtk.STOCK_REFRESH)
        self.wow_address_bar = gtk.Entry()

        self.many_back.connect('clicked', self.go_back)
        self.such_forward.connect('clicked', self.go_forward)
        self.very_refresh.connect('clicked', self.refresh_page)
        self.wow_address_bar.connect('activate', self.load_page)

        self.so_navigation.pack_start(self.many_back, False)
        self.so_navigation.pack_start(self.such_forward, False)
        self.so_navigation.pack_start(self.very_refresh, False)
        self.so_navigation.pack_start(self.wow_address_bar)

        # Create view for webpage
        self.very_view = gtk.ScrolledWindow()
        self.such_webview = webkit.WebView()
        self.such_webview.open('http://brobin.me')
        self.such_webview.connect('title-changed', self.change_title)
        self.such_webview.connect('load-committed', self.change_url)
        self.very_view.add(self.such_webview)

        # Add everything and initialize
        self.wow_container = gtk.VBox()
        self.wow_container.pack_start(self.so_navigation, False)
        self.wow_container.pack_start(self.very_view)

        self.much_window.add(self.wow_container)
        self.much_window.show_all()
        gtk.main()

    def load_page(self, widget):
        so_add = self.wow_address_bar.get_text()
        if so_add.startswith('http://') or so_add.startswith('https://'):
            self.such_webview.open(so_add)
        else:
            so_add = 'http://' + so_add
            self.wow_address_bar.set_text(so_add)
            self.such_webview.open(so_add)

    def change_title(self, widget, frame, title):
        self.much_window.set_title('Wow So ' + title)

    def change_url(self, widget, frame):
        uri = frame.get_uri()
        self.wow_address_bar.set_text(uri)

    def go_back(self, widget):
        self.such_webview.go_back()

    def go_forward(self, widget):
        self.such_webview.go_forward()

    def refresh_page(self, widget):
        self.such_webview.reload()

wow = Doge()
