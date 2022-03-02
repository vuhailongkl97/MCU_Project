import time
import random as rand
from datetime import datetime

try:
	while True :
		print "device id=%d, wind speed =%d , temp %d update at %s"\
				%(rand.randint(1,34),rand.randint(1,34),rand.randint(1,100), datetime.now())
		time.sleep(1)
except KeyboardInterrupt: 
	print("finish")

