from tkinter import *
import tkinter.filedialog
import tkinter.messagebox
from tkinter.colorchooser import askcolor
import datetime
import webbrowser
from tkinter.filedialog import askopenfilename, asksaveasfilename

def line():
    lin = "_" * 180
    text.insert(INSERT,lin)
    
def date():
    date = datetime.date.today()
    text.insert(INSERT,date)

def normal():
    text.config(font = ("Arial", 10))

def bold():
    text.config(font = ("Arial", 10, "bold"))

def underline():
    text.config(font = ("Arial", 10, "underline"))

def italic():
    text.config(font = ("Arial",10,"italic"))

def font():
    (triple,color) = askcolor()
    if color:
        text.config(foreground=color)
        
def kill():
    root.destroy()

def about():
    pass

def opn():
    text.delete(1.0 , END)
    file = open(askopenfilename() , 'r')
    if file != '':
        txt = file.read()
        text.insert(INSERT,txt)
    else:
        pass

    

def save():
    filename = asksaveasfilename()
    if filename:
        alltext = text.get(1.0, END)                      
        open(filename, 'w').write(alltext)

#def print():
#    text.print()

    

def copy():
    text.clipboard_clear()
    text.clipboard_append(text.selection_get()) 

def paste():
    try:
        teext = text.selection_get(selection='CLIPBOARD')
        text.insert(INSERT, teext)

    except:
        tkinter.messagebox.showerror("Error")

def clear():
    sel = text.get(SEL_FIRST, SEL_LAST)
    text.delete(SEL_FIRST, SEL_LAST)

def clearall():
    text.delete(1.0 , END)

def selectall():
    text.tag_add('sel', '1.0', 'end')
    return "break"

def background():
    (triple,color) = askcolor()
    if color:
        text.config(background=color)

def about():
    ab = Toplevel(root)
    txt = "New Notepad\nNew Notepad Version:11.2.3\nemail:new@notepad.org\n Developed by:Aayush"
    la = Label(ab,text=txt,foreground='blue')
    la.pack()
    
#def undo():
#   tkinter.undo()

def google():

    webbrowser.open('http://www.google.com')

def duckduckgo():
    webbrowser.open('https://duckduckgo.com')

def gmail():
    webbrowser.open('https://accounts.google.com')

def youtube():
    
    webbrowser.open('https://www.youtube.com')

def facebook():
    
    webbrowser.open('https://www.facebook.com/')

    

def search():
    sel = text.get(SEL_FIRST, SEL_LAST)
    webbrowser.open('https://www.google.com/search?q='+sel)
    

root = Tk()
root.title("New Notepad")
menu = Menu(root)
filemenu = Menu(root)
root.config(menu = menu)
menu.add_cascade(label="File", menu=filemenu)
filemenu.add_command(label="Open", command=opn)
filemenu.add_command(label="Save", command=save)
#filemenu.add_command(label="Print", command=print)
filemenu.add_separator()
filemenu.add_command(label="Exit", command=kill)

modmenu = Menu(root)
menu.add_cascade(label="Edit",menu = modmenu)
modmenu.add_command(label="Copy", command = copy)
modmenu.add_command(label="Paste", command=paste)
#modmenu.add_command(label="Undo", command=undo)
modmenu.add_separator()
modmenu.add_command(label = "Select All",command =selectall)
modmenu.add_command(label = "Clear", command = clear)
modmenu.add_command(label = "Clearall", command = clearall)


insmenu = Menu(root)
menu.add_cascade(label="Insert",menu= insmenu)
insmenu.add_command(label="Date",command=date)
insmenu.add_command(label="Line",command=line)


formatmenu = Menu(menu)
menu.add_cascade(label="Format",menu = formatmenu)
formatmenu.add_cascade(label="Color", command = font)
formatmenu.add_cascade(label="Background", command = background)
formatmenu.add_separator()
formatmenu.add_radiobutton(label='Normal',command=normal)
formatmenu.add_radiobutton(label='Bold',command=bold)
formatmenu.add_radiobutton(label='Underline',command=underline)
formatmenu.add_radiobutton(label='Italic',command=italic)

webmenu = Menu(menu)
menu.add_cascade(label="Web", menu=webmenu)
webmenu.add_command(label="Google", command=google)
webmenu.add_command(label="DuckDuckGo", command=duckduckgo)
webmenu.add_command(label="Gmail", command=gmail)
webmenu.add_command(label="YouTube", command=youtube)
webmenu.add_command(label="Facebook", command=facebook)

helpmenu = Menu(menu)
menu.add_cascade(label="Help", menu=helpmenu)
helpmenu.add_command(label="New Notepad info ", command=about)
helpmenu.add_command(label="Search ", command=search)

text = Text(root,height=40, width=180,font = ("Arial", 10),background='#DFAE74')
scroll = Scrollbar(root, command=text.yview)
scroll.config(command=text.yview)                  
text.config(yscrollcommand=scroll.set)           
scroll.pack(side=RIGHT, fill=Y)
text.focus()
text.pack()
root.resizable(1,1)
root.mainloop()
