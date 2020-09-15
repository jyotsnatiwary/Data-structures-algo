from tkinter import *
import webbrowser

class MainClass():

    def __init__(self,master):
        self.parent=master
        self.gui()

    def gui(self):
        self.Source=StringVar()
        #This next line I just tried out to use 'what' instead of 'str(self.Source) in def search(self)
        what=Entry(myGUI, textvariable=self.Source).grid(row=9, column=2) 

        label4=Label(myGUI, text='Key words:', fg= 'Black').grid(row=9, column=1)

        button4=Button(myGUI, text="  Search  ", command=self.search).grid(row=18, column=1)


    #def search(self):
           # webbrowser.open('http://google.com/?gws_rd=cr&ei=qr5cU8GJGMnStAao1YG4BA#q=' + str(self.Source.get))

    def search(self):
         webbrowser.open('http://google.com/?gws_rd=cr&ei=qr5cU8GJGMnStAao1YG4BA#q=' + str(self.Source.get()))

if __name__ == '__main__':
    myGUI=Tk()
    app=MainClass(myGUI)
    myGUI.geometry("300x100+100+200")
    myGUI.title('Google search')
    myGUI.mainloop()
