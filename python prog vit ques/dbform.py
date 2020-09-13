import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database= "jyot"
)

mycursor = mydb.cursor()

mycursor.execute("CREATE TABLE registration form (name VARCHAR(255), e mail VARCHAR(255), contact VARCHAR(255),gender VARCHAR(255), state VARCHAR(255))")

