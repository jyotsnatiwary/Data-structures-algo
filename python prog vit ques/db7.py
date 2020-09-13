import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="jyot"
)

mycursor = mydb.cursor()

sql = "INSERT INTO customers (name, address) VALUES (%s, %s)"
val = ("berry", "hong 21")
mycursor.execute(sql, val)

mydb.commit()

print( "record inserted.")
