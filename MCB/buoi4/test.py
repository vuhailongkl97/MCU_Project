import pymysql as pl 
from datetime import datetime
from random import randint
import time
#datetime.now().strftime('%Y-%m-%d %H:%M:%S')

sql_create_table = """CREATE TABLE sensors(
		id INT(10) PRIMARY KEY  auto_increment , 
		sensor_id int(3) not null, 
		mlong    int(3) not null,
		lat int(3) not null, 
		temperature int(3) not null, 
		humidity int(3) not null, 
		rain     int(3) not null,
		status_weather varchar(20),
		time datetime not null
		)
	  """
sql_insert = """insert into sensors(sensor_id, mlong, lat, temperature, humidity, rain,status_weather , time) 	
				values(%d , %d , %d, %d, %d, %d, '%s', '%s')
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

def insert_data(sensor_id, mlong, lat,  temperature, humidity, rain, status_weather, time):
		cursor.execute(sql_insert %( sensor_id, mlong, lat,  temperature, humidity, rain, status_weather, time ))
		db.commit()


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



weather = ["mua phun", "mua nhe" , "mua rao", "bao" ] 

#create table
create_table()

#def insert_data(sensor_id, mlong, lat,  temperature, humidity, rain, status_weather, time):

#insert 10 gia tri random 
for i in range(0,10):
	#current_time =   datetime.now().strftime('%Y-%m-%d %H:%M:%S')
	current_time =   datetime.now()
	sensor_id = randint(1,4);
	mlong = sensor_id
	lat = sensor_id 
	rain = randint(0,1)
	temperature = randint(20, 30)
	humidity = randint(80, 100)
	status_weather = weather[randint(0,3)]

	insert_data( sensor_id , mlong , lat , temperature , humidity , rain,status_weather, current_time)

cursor.execute(sql_get % ("temperature","desc") )
data = cursor.fetchall()	
	
for i in range(0,3):
		ids = data[i][1]
		mlong = data[i][2]
		lat = data[i][3]
		temperature = data[i][4]
		humidity = data[i][5]
		rain = data[i][6]
		status_weather = data[i][7]
		time = data[i][8].strftime("%Y-%m-%d %H:%M:%S")
		print("%2d  %2d %2d %3d %3d %2d  %15s %20s" %(ids, mlong, lat , temperature, humidity, rain , status_weather, time))

close_db()
