from PIL import Image
from numpy import *
import os
import show_images

DATASETDIR = '/path/to/your/dataset/directory/'

def perform_search(filename):
 #create an image object using Image.open method for the given image
 im = Image.open(filename)

 #we can use histogram method of image object to automatically build our histogram
 #we then convert the histogram array to numpy array to perform calculations
 search_histo = array(im.histogram())

 #create an empty list to store distances
 dist = []

 #get all the images of the dataset directory
 files = os.listdir(DATASETDIR)

 #declare the structure of the data for your dist list
 #It is only to perform sorting using numpy
 dtype = [('name', 'S100'), ('distance', float)]

 #Now we calculate euclidean distance between our search_histo and all images histograms
 for file in files:
  imob = Image.open(os.path.join(DATASETDIR, file))
  histo = array(imob.histogram())
  
  #Euclidean Distance Calculation
  try:
   diff = histo - search_histo
   sq = square(diff)
   total = sum(sq)
   result = sqrt(total)
   dist.append((file, result))
  except ValueError:
   pass

 
 #convert our list to numpy array with given data type
 distance = array(dist, dtype=dtype)

 #sort the array in increasing order to get top 10 results
 sort_dist = sort(distance, order='distance')

 top10 = sort_dist[:11]
 
 #show the result images in a window
 show_images.show_images(top10[1:])
