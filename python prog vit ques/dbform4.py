import tkinter as tk
from tkinter import *
from tkinter.ttk import *

class Form():
    
    def abc(c):
        
        a=tk.Tk()
        a.title("IT Desk")
        x=tk.Label(a,text="REGISTRATION FORM",font=('Arial',20),fg=("red"),bg=("yellow"))
        x.grid(row=0, column=1)

        b=tk.Label(a,text="name")
        b.grid(row=1, column=0)
        
        c=tk.Entry(a,text="name")
        c.grid(row=1, column=1)
        


        def click():
           #print("saved successfully")
            print (c)
        btn=Button(a,text="Save",command=click)
        btn.grid(row=7,column=1)
            

obj=Form()
obj.abc()
