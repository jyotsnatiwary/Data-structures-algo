import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="your",
  passwd=""
)

mycursor = mydb.cursor()

mycursor.execute("CREATE DATABASE mydatabase")
