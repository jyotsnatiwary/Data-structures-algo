import pymongo
dblist = myclient.database_names()
if "mydatabase" in dblist:
  print("The database exists.")
