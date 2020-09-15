main = tk()
main.title("FSX")
main.geometry('640x480')

frame1 = ttk.Frame(main, height=200, width=400)
frame1.pack()

entry = Entry(frame1, width=30)
entry.pack()

button1 = ttk.Button(frame1, text="Search", command=find_files)
button1.pack()
button1.bind ('<ButtonPress>', lambda e: progressbar.start())

button2 = ttk.Button(frame1, text="Quit")
button2.pack()
button2.bind ('<ButtonPress>', lambda e: exit())

progressbar = ttk.Progressbar(frame1, orient = HORIZONTAL, length = 200,      mode = 'indeterminate')
progressbar.pack()
#progressbar.start()

frame2 = ttk.Frame(main, height=200, width=400)
frame2.pack()

listbox = Listbox(frame2, height=200, width=400)
listbox.pack(fill=BOTH, expand=YES)

progressbar.stop()

main.mainloop()
