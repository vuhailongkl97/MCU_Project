def cong(a,b):
	return (a + b)

def tru(a,b):
	return (a - b)

def nhan(a,b):
	return a*b

def chia(a,b):
	if( b == 0):
		print("divide to 0 , error\n");
	else :
		return a*1.0/b;

def xap_xep_1_chieu(a):

	for i in range(0,len(a)):
		for j in range(0 , i +1 ):
			if a[i] < a[j]:
				temp = a[i]
				a[i] = a[j]
				a[j] = temp

def xap_xep_2_chieu(a):
	row = len(a)
	col = len(a[0])
	print("row = %d\ncol=%d" %(row , col))
	for i in range(0,row):
		xap_xep_1_chieu(a[i])


a = [[1,3,0] ,[ 6,7,1]]

xap_xep_2_chieu(a)
print(a)

