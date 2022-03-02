import random

def hello(a):
	if (a =="root"):
		print("hello root")
	else :
		print("you isn't root\n")
	

def get_array_random(xmin,xmax ,sz):
	a = []
	for i in range(0 , sz):
		a.append(random.randint(xmin,xmax));
	return a;
	
def get_matrix_random(xmin,xmax, w , h):
	c=[];	
	for i in range (0,h):
		b = get_array_random(xmin,xmax,w)	
		c.append(b)
	return c;

def print_rectangle(w,h ):
	for j in range(0,h):
		for i in range(0 ,w):
			if (i == 0) or  (i == w-1) or (j == 0) or (j == h-1):
				print('*',end='')
			else :
				print(" ",end='')
		print();
	
