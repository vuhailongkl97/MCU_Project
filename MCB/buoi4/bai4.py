import pymysql as pl 
from datetime import datetime
from random import randint
import time
#datetime.now().strftime('%Y-%m-%d %H:%M:%S')

sql_create_table = """CREATE TABLE sensors(
		id INT(10) PRIMARY KEY  auto_increment , 
		temperature int(3) not null, 
		humidity int(3) not null, 
		time datetime not null
		)
	  """
sql_insert = """insert into sensors(temperature, humidity, time) 	
				values(%d , %d ,'%s')
			"""

sql_show = """select * from sensors """

sql_update = """update sensors set temperature=%d, humidity=%d where id=%d"""

sql_delete = """delete from  sensors  where id=%d"""

sql_get = "SELECT * FROM sensors ORDER BY %s %s"

db = pl.connect("localhost", "root", "1" , "WSN")
cursor = db.cursor()

def check_version():
	cursor.execute("SELECT VERSION()");
	data = cursor.fetchone()

	print ("Database version :%s" % data)

def create_table():
	cursor.execute("DROP TABLE IF EXISTS sensors" )
	cursor.execute(sql_create_table)

def insert_data(temperature, humidity, time):
	try:
		cursor.execute(sql_insert %( temperature, humidity, time ))
		db.commit()

	except:
		db.rollback()

def get_data():
	try:
		cursor.execute(sql_show)
		result = cursor.fetchall()	
		return result
	
	except:
		return "khong co du lieu"

def update_data(temperature, humidity, ids):
	try:
		cursor.execute(sql_update % (temperature, humidity, ids))
		db.commit()
	except:
		db.rollback()

def delete_data(ids):
	try:
		cursor.execute(sql_delete %(ids) )
		db.commit()

	except:
		db.rollback()

def close_db():
	db.close()


#create table
create_table()

#insert 10 gia tri random 
for i in range(0,10):
	#current_time =   datetime.now().strftime('%Y-%m-%d %H:%M:%S')
	current_time =   datetime.now()
	insert_data(randint(1,100) , randint(1,100) , current_time)


field_sort = input("xap xep du lieu theo  loai du lieu nao\ntemperature\nhumidity\ntime\n");
if ( field_sort in "temperature"):
	filed_sort = "temperature"
elif  field_sort in "humidity":
	field_sort = "humidity"
else :
	field_sort = "time"

type_sort  = input("desc/asc   : ");

try:
	cursor.execute(sql_get % (field_sort,type_sort) )
	data = cursor.fetchall()	
	for i in range(0,len(data)):
		ids = data[i][0]
		temperature = data[i][1]
		hum = data[i][2]
		time = data[i][3].strftime("%Y-%m-%d %H:%M:%S")
		print("%10d %10d %10d %20s" %(ids, temperature , hum, time))
except:
	print("\nsyntax error")

close_db()
