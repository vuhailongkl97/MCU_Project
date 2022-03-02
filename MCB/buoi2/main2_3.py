from random import randint
from time import sleep
from datetime import datetime


print "Chuong trinh lay cac gia tri ngau nhien"

try:
	while(1):
		temperature = randint(28,30)
		humitity = randint(80,90)
		time_now = datetime.now()

		print "cap nhap luc %s" % str(time_now)
		print "nhiet do  %s" % str(temperature)
		print "do am  %s" % str(humitity)
		print "---------------------"
		sleep(1)


except KeyboardInterrupt:
	print "chuong trinh ket thuc"


















