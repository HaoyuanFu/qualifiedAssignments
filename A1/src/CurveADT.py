## @file CurveADT.py
#  @author Haoyuan(Harry) Fu
#  @brief Provides the CurveT ADT class for representing curves
#  @date 1/22/2018

from SeqADT import *
import numpy as np

## @brief An ADT that represents a curve
class CurveT:

    ## @brief CurveT constructor
    #  @details Initializes a CurveT object using a given input data file
    #           which should have two columns of data, with each data
    #           entry in a row separated by a comma and a space, and
    #           each row separated by a newline
    #  @param self The object pointer
    #  @param s The filename of the input data file
    def __init__(self, s):
        self.seqX = SeqT()
        self.seqY = SeqT()
        i = 0
        with open(s, 'r') as f:
            for row in f:
                eles = row.split(', ')
                if len(eles) == 2:
                    self.seqX.add(i, float(eles[0]))
                    self.seqY.add(i, float(eles[1]))
                    i += 1

    ## @brief Does Linearly interpolation to get a y at x
    #  @details There should be at least two data points and
    #           there should be at least one data point to
    #           the left of x (overlap allowed) and also
    #           at least one data point to the right of x
    #           (overlap allowed)
    #  @param self The object pointer
    #  @param x The given x
    #  @return The interpolated y
    #  @exception ValueError raises for illegal value
    def linVal(self, x):
        try:
            i1 = self.seqX.indexInSeq(x)
        except IndexError:
            raise ValueError('illegal x')
        i2 = i1 + 1
        x1, y1 = self.seqX.get(i1), self.seqY.get(i1)
        x2, y2 = self.seqX.get(i2), self.seqY.get(i2)
        y = (y2 - y1) * (x - x1) / (x2 - x1) + y1
        return y 

    ## @brief Does quadratically interpolation to get a y at x
    #  @details There should be at least three data points and
    #           there should be at least one data point to
    #           the left of x (overlap allowed) and also
    #           at least one data point to the right of x
    #           (overlap allowed)
    #  @param self The object pointer
    #  @param x The given x
    #  @return The interpolated y
    #  @exception ValueError raises for illegal value or insufficient data points
    def quadVal(self, x):
        try:
            i1 = self.seqX.indexInSeq(x)
        except IndexError:
            raise ValueError('illegal x')
        if i1 == 0:
            if self.seqX.size() < 3:
                raise ValueError('insufficient data points')
            i0, i1, i2 = 0, 1, 2
        else:
            i0, i2 = i1 - 1, i1 + 1
        x0, y0 = self.seqX.get(i0), self.seqY.get(i0)
        x1, y1 = self.seqX.get(i1), self.seqY.get(i1)
        x2, y2 = self.seqX.get(i2), self.seqY.get(i2)
        y = y1 + (y2 - y0) * (x - x1) / (x2 - x0) + (y2 - 2 * y1 + y0) * (x - x1)**2 / (2 * (x2 - x1)**2)
        return y

    ## @brief Uses least squares polynomial fitting to find a y at x
    #  @details The ployfit function of numpy is wrapped inside
    #  @param self The object pointer
    #  @param n The degree of polynomial
    #  @param x The given x
    #  @return The interpolated y
    #  @exception Exception raises by numpy.polyfit if any
    #  @the numpy command I found here: https://docs.scipy.org/doc/numpy-1.13.0/reference/index.html
    def npolyVal(self, n, x):
        xs = []
        ys = []
        for i in range(self.seqX.size()):
            xs.append(self.seqX.get(i))
            ys.append(self.seqY.get(i))
        zs = np.polyfit(xs, ys, n)
        p = np.poly1d(zs)
        y = p(x)
        return y
