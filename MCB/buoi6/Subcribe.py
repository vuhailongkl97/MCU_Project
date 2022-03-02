import paho.mqtt.client as mqtt
import my_lib_sql as ml 

MQTT_Broker = "localhost"
MQTT_Port   = 1883 
Keep_Alive_Interval = 45
MQTT_Topic = "home/sensors"


def on_message(client, userdata, msg):
	print ("MQTT Data Received ... ")
	print ("MQTT Topic : "+ msg.topic)
	print ("DATA : " + str(msg.payload))
	print ("saving .....")
	ml.insert_table(msg.payload)
	print ("done !!! ")


def on_connect(client, userdata, flags, rc):
	if rc != 0: #ket noi thanh cong khi rc = 0
		pass
		print("Unable to connect to MQTT Broker...")
	else:
		print("Connected with MQTT Broker: " + str(MQTT_Broker))
	client.subscribe(MQTT_Topic,0)


ml.create_table()
client = mqtt.Client()
client.username_pw_set(username="long",password="1")
client.on_connect = on_connect
client.on_message = on_message

client.connect(MQTT_Broker, MQTT_Port, Keep_Alive_Interval)
client.loop_forever()

