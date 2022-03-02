import paho.mqtt.client as mqtt
import my_lib_sql as ml 
import ast

MQTT_Broker = "localhost"
MQTT_Port   = 1883
Keep_Alive_Interval = 45
MQTT_Topic1 = "home/sensors/datetime"
MQTT_Topic2 = "home/sensors/temperature"
MQTT_Topic3 = "home/sensors/humidity"
MQTT_Topic4 = "longvh_test"

SensorID ="dht11" 
Date_and_Time ="123" 
Temperature =0 
Humidity =0 
cnt_check = 0


def on_message(client, userdata, msg):
	global SensorID , Date_and_Time, Temperature, Humidity, cnt_check
	print ("MQTT Topic : "+ msg.topic)
	#print ("DATA : " + str(msg.payload))
	print ("saving .....")
	json_data =  msg.payload
	json_Dict = ast.literal_eval(json_data.decode('utf-8'))
	#print (json_Dict)

	if ( msg.topic ==  MQTT_Topic1 ):
		SensorID = json_Dict['Sensor_ID']
		Date_and_Time = json_Dict['Date']
		cnt_check = cnt_check + 1
	elif ( msg.topic ==  MQTT_Topic2):
		Temperature = json_Dict['Temperature']
		cnt_check = cnt_check + 1
	elif (msg.topic ==  MQTT_Topic3):
		Humidity = json_Dict['Humidity']
		cnt_check = cnt_check + 1
	else:
		print("incorrect topic")
	print(cnt_check)	
	if( cnt_check % 3 == 0):
		cnt_check = 0	
		print (SensorID , Date_and_Time, Temperature, Humidity)
		ml.insert_table_with_raw_data(SensorID , Date_and_Time, Temperature, Humidity)

def on_connect(client, userdata, flags, rc):
	if rc != 0: #ket noi thanh cong khi rc = 0
		pass
		print("Unable to connect to MQTT Broker...")
	else:
		print("Connected with MQTT Broker: " + str(MQTT_Broker))
	client.subscribe(MQTT_Topic1,0)
	client.subscribe(MQTT_Topic2,0)
	client.subscribe(MQTT_Topic3,0)
	client.subscribe(MQTT_Topic4,0)


ml.create_table()
client = mqtt.Client()
client.username_pw_set(username="long",password="1")
client.on_connect = on_connect
client.on_message = on_message

client.connect(MQTT_Broker, MQTT_Port, Keep_Alive_Interval)
client.loop_forever()

