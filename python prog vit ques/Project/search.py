from tkinter import *
import urllib.request
def go():
	text.delete(1.0, END)
	with urllib.request.urlopen(entry.get()) as response:
		received_html = response.read()
	text.insert(1.0, received_html)

browser_window = Tk()
browser_window.title('knowpapa browser')
label = Label(browser_window, text= 'Enter URL:')
entry = Entry(browser_window)
entry.insert(END, "http://knowpapa.com")
button = Button(browser_window, text='Go', command = go)
text = Text(browser_window)
label.pack(side=TOP)
entry.pack(side=TOP)
button.pack(side=TOP)
text.pack(side= TOP)
browser_window.mainloop()
