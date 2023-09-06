import random
import numpy
import cv2

def convert(cad):

    tam = 1

    bas = [307,311,313,317,331,337,347,349,353,359]
    mod = [7,9,21,33,87,93,97,103,123,181]
	
    for i in range(len(mod)):
        mod[i] += 1000000000

    vect = []

    for i in range(min(len(bas),len(mod),tam)):
        num = 0
        for j in range(len(cad)):
            num = (num*bas[i] + ord(cad[j])) % mod[i]
        vect.append(num)

    return vect;

def getrandom():
	num = 0;
	for i in range(len(vect)):
		random.seed(vect[i])
		num ^= random.randint(1,10**9)
	for i in range(len(vect)):
		vect[i] ^= num
	return num;


def encrypt(val):
	return (val+getrandom())%256

def decrypt(val):
	return (val+256-getrandom()%256)%256

cad = input()
vect = convert(cad)
flag = int(input())

image = cv2.imread("imagen.png")
image2 = numpy.zeros((image.shape[0],image.shape[1],3),numpy.uint8)

per1 = []
per2 = []

for i in range(image.shape[0]):
	per1.append(i)

for i in range(image.shape[1]):
	per2.append(i)

random.seed(getrandom())
random.shuffle(per1)

random.seed(getrandom())
random.shuffle(per2)

if flag == 0:
	for i in range (image.shape[0]):
		for j in range(image.shape[1]):
			image2.itemset((i,j,0),decrypt(image.item(per1[i],per2[j],0)));
			image2.itemset((i,j,1),decrypt(image.item(per1[i],per2[j],1)));
			image2.itemset((i,j,2),decrypt(image.item(per1[i],per2[j],2)));
else:
	for i in range (image.shape[0]):
		for j in range(image.shape[1]):
			image2.itemset((per1[i],per2[j],0),encrypt(image.item(i,j,0)));
			image2.itemset((per1[i],per2[j],1),encrypt(image.item(i,j,1)));
			image2.itemset((per1[i],per2[j],2),encrypt(image.item(i,j,2)));


cv2.imwrite("imagen.png",image2)