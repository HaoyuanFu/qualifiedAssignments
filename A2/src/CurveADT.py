## @file CurveADT.py
#  @author Harry Fu
#  @brief Provides the CurveT ADT class for representing curves
#  @details Provides the CurveT ADT class for representing curves with the assumption:
#           The user will not request function evaluations that would cause the
#           interpolation to select index values outside of where the function
#           is defined.
#  @date 2/14/2018


from SeqServices import *
from Exceptions import *


## @brief An ADT that represent the curve
#  @details With the assumption: The user will not request function
#           evaluations that would cause the interpolation to select
#           index values outside of where the function is defined
class CurveT:
    # the maximum order
    MAX_ORDER = 2
    # the delta x
    DX = 1e-3

    ## @brief CurveT constructor
    #  @details Initializes a CurveT object
    #  @param self The object pointer
    #  @param X The x sequence
    #  @param Y The y sequence
    #  @param i The order
    #  @exception IndepVarNotAscending raises for non-ascending independant variable sequence
    #  @exception SeqSizeMismatch raises for mismatched sequence sizes
    #  @exception InvalidInterpOrder raises for illegal interpolation order
    def __init__(self, X, Y, i):
        if not isAscending(X):
            raise IndepVarNotAscending(X)
        if len(X) != len(Y):
            raise SeqSizeMismatch(X, Y)
        if i < 1 or i > CurveT.MAX_ORDER:
            raise InvalidInterpOrder(i)

        self.X, self.Y = list(X), list(Y)
        self.minx, self.maxx = X[0], X[-1]
        self.o = i
        self.f = lambda v: interp(self.X, self.Y, self.o, v)

    ## @brief Gets the minimum x
    #  @param self The object pointer
    #  @return The minimum x
    def minD(self):
        return self.minx

    ## @brief Gets the maximum x
    #  @param self The object pointer
    #  @return The maximum x
    def maxD(self):
        return self.maxx

    ## @brief Gets the order of curve
    #  @param self The object pointer
    #  @return The order
    def order(self):
        return self.o

    ## @brief Evaluates the y value at the given x
    #  @param self The object pointer
    #  @param x The x value
    #  @return The evaluated y value
    #  @exception OutOfDomain raises for illegal x value
    def eval(self, x):
        self.__sanityCheckX__(x)
        return self.f(x)

    ## @brief Approximates first derivative using forward divided difference
    #  @param self The object pointer
    #  @param x The x value
    #  @return The first derivative
    #  @exception OutOfDomain raises for illegal x value
    def dfdx(self, x):
        self.__sanityCheckX__(x)
        return (self.f(x + CurveT.DX) - self.f(x)) / CurveT.DX

    ## @brief Approximates second derivative using forward divided difference
    #  @param self The object pointer
    #  @param x The x value
    #  @return The second derivative
    #  @exception OutOfDomain raises for illegal x value
    def d2fdx2(self, x):
        self.__sanityCheckX__(x)
        return (self.f(x + 2 * CurveT.DX) - 2 * self.f(x + CurveT.DX) + self.f(x)) / (CurveT.DX ** 2)

    ## @brief Sanity-Checks the x value
    #  @param x The x value
    #  @exception OutOfDomain raises for illegal x value
    def __sanityCheckX__(self, x):
        if not self.minx <= x <= self.maxx:
            raise OutOfDomain(self.minx, x, self.maxx)


## @brief Interpolates the curve
#  @param X The x sequence
#  @param Y The y sequence
#  @param o The order of the curve
#  @param v The v value
#  @return the interpolated y value
def interp(X, Y, o, v):
    i = index(X, v)
    if o == 1:
        return interpLin(X[i], Y[i], X[i + 1], Y[i + 1], v)
    return interpQuad(X[0], Y[0], X[1], Y[1], X[2], Y[2], v) if i == 0 else \
        interpQuad(X[i - 1], Y[i - 1], X[i], Y[i], X[i + 1], Y[i + 1], v)
