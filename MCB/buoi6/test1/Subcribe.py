import paho.mqtt.client as mqtt
import my_lib_sql as ml 
import ast
from datetime import datetime

MQTT_Broker = "localhost"
MQTT_Port   = 1883
Keep_Alive_Interval = 45
MQTT_Topic1 = "long/heart_rate"


def on_message(client, userdata, msg):
	print ("MQTT Topic : "+ msg.topic)
	print ("saving .....")
	json_data =  msg.payload
	json_Dict = ast.literal_eval(json_data.decode('utf-8'))
	if ( msg.topic ==  MQTT_Topic1 ):
		
		heart_rate = json_Dict['heart_rate']
		status = ""
		if( heart_rate >= 50 and heart_rate <60 ):
			status = "low"
		elif (heart_rate >=60 and heart_rate < 70):
			status = "normal"
		elif (heart_rate >=70 and heart_rate < 100):
			status = "high"
		elif (heart_rate >=100 and heart_rate < 120):
			status = "warning"
		print(heart_rate , status)

		Date_and_Time = (datetime.today()).strftime("%Y-%m-%d %H:%M:%S")
		ml.insert_table_with_raw_data(heart_rate, status,Date_and_Time)
	else:
		print("incorrect topic")

def on_connect(client, userdata, flags, rc):
	if rc != 0: #ket noi thanh cong khi rc = 0
		pass
		print("Unable to connect to MQTT Broker...")
	else:
		print("Connected with MQTT Broker: " + str(MQTT_Broker))
	client.subscribe(MQTT_Topic1,0)


ml.create_table()
client = mqtt.Client()
client.username_pw_set(username="long",password="1")
client.on_connect = on_connect
client.on_message = on_message

client.connect(MQTT_Broker, MQTT_Port, Keep_Alive_Interval)
client.loop_forever()

