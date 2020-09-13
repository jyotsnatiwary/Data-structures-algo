import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="jyot"
)

mycursor = mydb.cursor()

sql = "DELETE FROM customers WHERE address = 'bezing 21'"

mycursor.execute(sql)

mydb.commit()

print(mycursor.rowcount, "record(s) deleted")
