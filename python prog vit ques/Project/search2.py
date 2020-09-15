from tkinter import *
from tkinter import ttk
import glob
import os

search = '*log'


found_files = []

for dirname, dirnames, filenames in os.walk('/tmp'):
    for i in glob.glob(dirname+'/'+search+'*'):
        print(i)
        found_files.append(i)



root = Tk()
root.geometry( "640x480" );


listbox = Listbox(root)

for a_file in found_files:
    listbox.insert(END, a_file)

listbox.pack(fill=BOTH, expand=YES)

root.mainloop()
