import tkinter as tk

import 
class InputForm(object):
    def __init__(self):
        self.root = tk.Tk()
        self.root.title('Input Form')
        self.num_a = ''
        self.num_b = ''
        self.frame = tk.Frame(self.root)
        self.frame2 = tk.Frame(self.root)
        self.frame.pack()
        self.frame2.pack()
        self.initialization()
    def initialization(self):
        r = self.frame
        k_a = tk.Label(r,text='Number A')
        k_a.grid(row=0, column=0)
        self.e_a = tk.Entry(r, text='NumA')
        self.e_a.grid(row=0, column=1)
        self.e_a.focus_set()
        k_b = tk.Label(r,text='Number B')
        k_b.grid(row=1, column=0)
        self.e_b = tk.Entry(r, text='NumB')
        self.e_b.grid(row=1, column=1)
        self.e_b.focus_set()
        r2 = self.frame2
        b = tk.Button(r2,text='Save',command=self.get_inputs)
        b.pack(side='left')
    def get_inputs(self):
        self.num_a = self.e_a.get()
        self.num_b = self.e_b.get()
        self.root.destroy()
    def get_values(self):
        return self.num_a, self.num_b
    def wait_for_input(self):
        self.root.mainloop()
dialog = InputForm()
dialog.wait_for_input()
num_a, num_b = dialog.get_values()
print('num a:', num_a)
print('num b:', num_b)
