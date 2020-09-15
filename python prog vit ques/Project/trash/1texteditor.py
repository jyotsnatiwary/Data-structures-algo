import tkinter
import ScrolledText # Because Tkinter textarea does not provide scrolling
#  abilities, we use this additional library
root = tkinter.Tk(className=" Just another Text Editor")
textPad = ScrolledText.ScrolledText(root, width=100, height=80)
textPad.pack()
root.mainloop()
