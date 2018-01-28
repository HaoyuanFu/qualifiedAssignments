## @file CurveADT
#  @author Thomas Shang
#  @brief Provides the CurveT ADT class for representing curves
#  @date 1/22/2018

import numpy
from SeqADT import SeqT

## @brief An ADT that represents a curve
class CurveT:

	## @brief CurveT constructor
	#  @details Initializes a CurveT object with x and y coordinates stored in sepereate SeqT objects
	#  @param s File name input for data to initialize object
	#  @exception FileNotFoundError throws if file name supplied does not exist
	def __init__(self, s):
		try:
			file = open(s, "r")
			self.x = SeqT();
			self.y = SeqT();
			index = 0
			for line in file:
				data = line.split(", ")
				self.x.add(index,float(data[0]))
				self.y.add(index,float(data[1]))
				index += 1
		except FileNotFoundError:
			print("File does not exist")
		

	## @brief Calculates the value of x based on the linear interpolation of the surrounding points
	#  @param x value of x coordinate
	#  @return The value of x calculated via linear interpolation
	def linVal(self,x):
		i = self.x.indexInSeq(x)
		return (self.y.get(i+1) - self.y.get(i))/(self.x.get(i+1) - self.x.get(i))*(x - self.x.get(i)) + self.y.get(i)


	## @brief Calculates the value of x based on the quadratic interpolation of the surrounding points
	#  @param x value of x coordinate
	#  @return The value of x calculated via quadratic interpolation
	def quadVal(self,x):
		i = self.x.indexInSeq(x)
		a =  self.y.get(i) + (self.y.get(i+1) - self.y.get(i-1))/(self.x.get(i+1) - self.x.get(i-1))*(x - self.x.get(i))
		b = (self.y.get(i+1) - 2*self.y.get(i) + self.y.get(i-1))/(2*(self.x.get(i+1) - self.x.get(i)) ** 2)*((x - self.x.get(i)) ** 2)
		return a+b

	## @brief Calculates the value of x by using the provided polynomial returned by the polyfit function
	#  @param n degree of polynomial function
	#  @param x value of x coordinate
	#  @return The value of x calculated via the provided polynomial by the polyfit function
	def npolyVal(self, n , x):
		p = numpy.polyfit(self.x.data, self.y.data, n)
		y = 0
		for i in range(n+1):
			y += p[i]*(x ** (n - i))

		return y
