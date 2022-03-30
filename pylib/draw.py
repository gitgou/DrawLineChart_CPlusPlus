# -*- coding: UTF-8 -*-
import matplotlib.pyplot as plt

def draw(k1, k2):
	x = [1,2,3,4,5,6,7,8,9,10] #点的横坐标
	print (x);
	print k1;
	print k2;
	plt.plot(x,k1,'s-',color = 'r',label="ATT-RLSTM")#s-:方形
	plt.plot(x,k2,'o-',color = 'g',label="CNN-RLSTM")#o-:圆形
	plt.xlabel("region length")#横坐标名字
	plt.ylabel("accuracy")#纵坐标名字
	plt.legend(loc = "best")#图例
	plt.show()

