import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="jyot"
)

mycursor = mydb.cursor()

sql = "SELECT * FROM regform"

mycursor.execute(sql)

myresult = mycursor.fetchall()

for x in myresult:
  print(x)
