from Tkinter import *
from PIL import Image, ImageTk
import os

DATASETDIR = '/path/to/your/dataset/directory/'

class MainFrame(Frame):
    def __init__(self, parent, *args, **kw):
  Frame.__init__(self, parent, *args, **kw)            

  # create a canvas object and a vertical scrollbar for scrolling it
  vscrollbar = Scrollbar(self, orient=VERTICAL)
  vscrollbar.pack(fill=Y, side=RIGHT, expand=False)

  canvas = Canvas(self, bd=0, highlightthickness=0,
                  yscrollcommand=vscrollbar.set)
  canvas.pack(side=LEFT, fill=BOTH, expand=True)
  vscrollbar.config(command=canvas.yview)

  # reset the view
  canvas.yview_moveto(0)

  # create a frame inside the canvas which will be scrolled with it
  self.interior = interior = Frame(canvas)
  interior_id = canvas.create_window(0, 0, window=interior,
                                     anchor=NW)

  # track changes to the canvas and frame width and sync them,
  # also updating the scrollbar
  def _configure_interior(event):
      # update the scrollbars to match the size of the inner frame
      size = (interior.winfo_reqwidth(), interior.winfo_reqheight())
      canvas.config(scrollregion="0 0 %s %s" % size)
      if interior.winfo_reqwidth() != canvas.winfo_width():
          # update the canvas's width to fit the inner frame
          canvas.config(width=interior.winfo_reqwidth())
  interior.bind('<Configure>', _configure_interior)

  def _configure_canvas(event):
      if interior.winfo_reqwidth() != canvas.winfo_width():
          # update the inner frame's width to fill the canvas
          canvas.itemconfigure(interior_id, width=canvas.winfo_width())
  canvas.bind('<Configure>', _configure_canvas)


def show_images(top10, root=None): 
 root = Tk()
 root.title("Similar Images")
 root.imageframe = MainFrame(root)
 root.imageframe.pack(fill=BOTH, expand=True)

 images = []
 imagetks = []
 imagepanels = []
 r=0

 size = 128, 128

 for image in top10:
  imagename = os.path.splitext(image[0])[0]
  img = Image.open(os.path.join(DATASETDIR, image[0]))
  img.thumbnail(size)
  images.append(img)
  imgtk = ImageTk.PhotoImage(images[-1])
  imagetks.append(imgtk)
  panel = Label(root.imageframe.interior, image=imagetks[-1])
  imagepanels.append(panel)
  imagepanels[-1].grid(row=r, column=0)
  r = r+1

 root.mainloop()
