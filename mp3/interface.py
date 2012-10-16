from mp3interface import *

try:
    import pygtk
    pygtk.require('2.0')
except:
    pass

try:
    import gtk
except:
    sys.exit(1)


class Interface:

    def organize(self, widget, entry):
        entry_text = entry.get_text()
        organizePath(self, entry_text)

    def search(self, widget, entry, text_buffer):
        entry_text = entry.get_text()
        searchMP3s(self, entry_text, text_buffer)

    def searchRefine(self, widget, entry, text_buffer):
        entry_text = entry.get_text()
        searchMP3Refine(self, entry_text, text_buffer)
        
    def destroy(self, widget, data=None):
        gtk.main_quit()

    def __init__(self):
        # Sets the main window.
        self.window = gtk.Window(gtk.WINDOW_TOPLEVEL)
        self.window.set_title("Skynet")
        self.window.connect("destroy", self.destroy)
        self.window.set_border_width(10)


        # Sets boxes (containers) for other widgets.
        # MainBox contains LeftBox and InfoBox. 
        self.MainBox = gtk.HBox(False, 0)

        # LeftBox contains OrgBox, CheckboxBox and SearchBox.
        self.LeftBox = gtk.VBox(False, 5)

        # InfoBox contains information about the last search.
        self.InfoBox = gtk.HBox(False, 0)

        # OrgBox contains the Path text entry and Organize button.
        self.OrgBox = gtk.VBox(True, 5)

        # CheckboxBox contains CheckboxLeft and CheckboxRight, and
        # those contain all 8 CheckButtons.
        self.CheckboxBox = gtk.HBox(True, 0)
        self.CheckboxBoxLeft = gtk.VBox(True, 5)
        self.CheckboxBoxRight = gtk.VBox(True, 5)

        # SearchBox contains the Search text entry and Search buttons.
        self.SearchBox = gtk.VBox(False, 5)

        # Sets buttons.
        # Sets check buttons (toggle).
        self.Length = gtk.CheckButton("Length")
        self.Title = gtk.CheckButton("Title")
        self.Artist = gtk.CheckButton("Artist")
        self.Album = gtk.CheckButton("Album")
        self.Genre = gtk.CheckButton("Genre")
        self.Year = gtk.CheckButton("Year")
        self.Bitrate = gtk.CheckButton("Bitrate")

        # Sets other buttons.
        self.Organize = gtk.Button("Organize")
        self.Search = gtk.Button("Search")
        self.SearchRefine = gtk.Button("Refine Search")


        # Sets text entry fields.
        # Text entry for the desired path. (referred to as
        # root in other parts of the code)
        self.Path = gtk.Entry()
        self.Path.set_max_length(50)
        self.Path.connect("activate", self.organize, self.Path)

        # Text entry for the search string.
        self.SearchParameter = gtk.Entry()
        self.SearchParameter.set_max_length(50)
        self.SearchParameter.connect("activate", self.search, self.SearchParameter)


        # Sets text view window.
        # This is used to print the strings returned from the search function.
        info = gtk.ScrolledWindow()
        info.set_size_request(400, 200)
        info.set_policy(gtk.POLICY_AUTOMATIC, gtk.POLICY_AUTOMATIC)
        info.set_shadow_type(gtk.SHADOW_ETCHED_IN)
        text_view = gtk.TextView()
        text_buffer = text_view.get_buffer()
        text_view.set_editable(False)
        text_view.set_cursor_visible(False)
        info.add(text_view)
        

        # Sets buttons' callbacks.
        self.Organize.connect("clicked", self.organize, self.Path)
        self.Search.connect("clicked", self.search, self.SearchParameter, text_buffer)
        self.SearchRefine.connect("clicked", self.searchRefine, self.SearchParameter, text_buffer)

        # searchFieldList is a function handling which fields should be used in the search.
        self.Length.connect("toggled", setFieldList, "Length")
        self.Title.connect("toggled", setFieldList, "Title")
        self.Artist.connect("toggled", setFieldList, "Artist")
        self.Album.connect("toggled", setFieldList, "Album")
        self.Genre.connect("toggled", setFieldList, "Genre")
        self.Year.connect("toggled", setFieldList, "Year")
        self.Bitrate.connect("toggled", setFieldList, "Bitrate")


        # Packs all widgets/buttons/windows.
        self.OrgBox.pack_start(self.Path)
        self.OrgBox.pack_start(self.Organize)
        self.CheckboxBox.pack_start(self.CheckboxBoxLeft)
        self.CheckboxBox.pack_start(self.CheckboxBoxRight)
        self.CheckboxBoxLeft.pack_start(self.Length)
        self.CheckboxBoxLeft.pack_start(self.Title)
        self.CheckboxBoxLeft.pack_start(self.Artist)
        self.CheckboxBoxLeft.pack_start(self.Album)
        self.CheckboxBoxRight.pack_start(self.Genre)
        self.CheckboxBoxRight.pack_start(self.Year)
        self.CheckboxBoxRight.pack_start(self.Bitrate)
        self.SearchBox.pack_start(self.SearchParameter)
        self.SearchBox.pack_start(self.Search)
        self.SearchBox.pack_start(self.SearchRefine)
        self.LeftBox.pack_start(self.OrgBox)
        self.LeftBox.pack_start(self.CheckboxBox)
        self.LeftBox.pack_start(self.SearchBox)
        self.InfoBox.pack_start(info, True, True, 5)
        self.MainBox.pack_start(self.LeftBox)
        self.MainBox.pack_start(self.InfoBox)
        self.window.add(self.MainBox)
        self.window.show()


        # Shows all widgets/buttons/windows.
        self.Path.show()
        self.Organize.show()
        self.OrgBox.show()
        self.CheckboxBox.show()
        self.CheckboxBoxLeft.show()
        self.CheckboxBoxRight.show()
        self.SearchBox.show()
        self.LeftBox.show()
        self.InfoBox.show()
        self.MainBox.show()
        self.Length.show()
        self.Title.show()
        self.Artist.show()
        self.Album.show()
        self.Genre.show()
        self.Year.show()
        self.Bitrate.show()
        self.SearchParameter.show()
        self.Search.show()
        self.SearchRefine.show()
        info.show()
        text_view.show()


if __name__ == "__main__":
    interface = Interface()
    gtk.main()



