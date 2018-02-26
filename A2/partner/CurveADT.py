## @file CurveADT.py
#  @author Kajoban Kuhaparan
#  @brief Provides a CurveT class for representing a curve
#  @date 20/02/2018

import SeqServices
import Exceptions 

## @brief An ADT that represents a curve
class CurveT:

    MAX_ORDER = 2
    DX = 1 * (10**(-3))

    ## @brief Interpolation function
    #  @details Calculates the linear or quadratic interpolation for a value on the curve
    #           based on the values index.
    #  @param X A sequence of X values representing x values of a curve
    #  @param Y A sequence of Y values representing y values of a curve
    #  @param o The order at which the interpolation should be calculated
    #  @param v The value which the interpolation should be calculated around. 
    def interp(X, Y, o, v):

        i = SeqServices.index(X, v)

        if o == 1:
            return SeqServices.interpLin(X[i], Y[i], X[i+1], Y[i+1], v)

        elif o == 2:
            return SeqServices.interpQuad(X[i-1], Y[i-1], X[i], Y[i], X[i+1], Y[i+1], v)
            

    ## @brief CurveT constructor
    #  @detials Initializes a CurveT object. Stores the minimum and maximum x values,
    #           the order of the curve, and an anonymous function that can be used to
    #           evaluated the function. Before constructing the CurveT object,
    #           ensures that the independant variable is increasing, the independant and
    #           dependant sequences are the same size, and that the order does not exceed the maximum order
    #  @param X A sequence of x values corresponding to a curve
    #  @param Y A sequence of y values corresponding to a curve
    #  @param i The order of the curve
    def __init__(self, X, Y, i):

        if SeqServices.isAscending(X) == False:
            raise Exceptions.IndepVarNotAscending("Independant variable x is not ascending")

        elif len(X) != len(Y):
            raise Exceptions.SizeSeqMismatch("Sequence sizes do not match")

        elif i not in range(1, CurveT.MAX_ORDER + 1):
            raise Exceptions.InvalidInterpOrder("Interpolation order is illegal")

        self.minx = X[0]
        self.maxx = X[len(X) - 1]
        self.o = i
        self.f = lambda v: CurveT.interp(X, Y, self.o, v) #creates an anonymous function and returns it

    ## @brief Returns the minimum x value of the curve
    #  @return self.minx The minimum x value of the curve
    def minD(self):

        return self.minx 

    ## @brief Returns the maximum x value of the curve
    #  @return self.maxx The maximum x value of the curve
    def maxD(self):

        return self.maxx 

    ## @brief Returns the order of the curve
    #  @return self.o The order of the curve
    def order(self):

        return self.o; 

    ## @brief Returns the y value of the curve evaluated at some x value.
    #  @details Ensures that the x value is included in the independant range before evaluating. 
    #  @param x The x value that the curve is being evaluated at
    #  @return self.f(x) The value of the curve evaluated at some x value
    def eval(self, x): 

        if (not (self.minx <= x)) or (not (x <= self.maxx)):
            raise Exceptions.OutOfDomain("Value to be evaluated out of domain of x")

        return self.f(x)

    ## @brief Returns the first derivative of the curve evaluated at some x value
    #  @details Ensures that the x value is included in the independant range before evaluating. 
    #  @param x The x value that the first derivative is being evaluated at
    #  @return (self.f(x + CurveT.DX) - self.f(x)) / CurveT.DX
    #           The first derivative of the curve evaluated at some x value
    def dfdx(self, x):

        if (not (self.minx <= x)) or (not (x <= self.maxx)):
            raise Exceptions.OutOfDomain("Value to be evaluated out of domain of x")

        return (self.f(x + CurveT.DX) - self.f(x)) / CurveT.DX  

    ## @brief Returns the second derivative of the curve evaluated at some x value
    #  @details Ensures that the x value is included in the independant range before evaluating. 
    #  @param x The x value that the second derivative is being evaluated at
    #  @return (self.f(x + 2*CurveT.DX) - 2*self.f(x + CurveT.DX)+ self.f(x)) / (CurveT.DX**2)
    #           The second derivative of the curve evaluated at some x value
    def d2fdx2(self, x):

        if (not (self.minx <= x)) or (not (x <= self.maxx)):
            raise Exceptions.OutOfDomain("Value to be evaluated out of domain of x")

        return (self.f(x + 2*CurveT.DX) - 2*self.f(x + CurveT.DX)+ self.f(x)) / (CurveT.DX**2)


        

    

        

        

