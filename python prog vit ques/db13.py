import mysql.connector

mydb = mysql.connector.connect(
  host="localhost",
  user="root",
  passwd="",
  database="jyot"
)

mycursor = mydb.cursor()

sql = "UPDATE customers SET address = 'bgp 21' WHERE address = 'london 21'"

mycursor.execute(sql)

mydb.commit()

print(mycursor.rowcount, "record(s) affected")
