## @file Plot.py
#  @author Harry Fu
#  @brief Provides the Plotting methods
#  @details Provides the Plotting methods with the assumption:
#           For plotting the user will select the number of subdivisions
#           to be small enough that there will not be an interpolation
#           problem with the end points.
#  @date 2/14/2018


from matplotlib import pyplot as plt
from CurveADT import CurveT
from Exceptions import *


## @brief Plots a sequence
#  @param X The x sequence
#  @param Y The y sequence
#  @exception SeqSizeMismatch raises for non-matched sequence size
def PlotSeq(X, Y):
    if len(X) != len(Y):
        raise SeqSizeMismatch()
    plt.scatter(X, Y, color='orange')
    plt.show()


## @brief Plots a curve
#  @param c The curve
#  @param n The number of points
def PlotCurve(c, n):
    X = []
    Y = []
    step = (c.maxD() - c.minD()) / (n - 1)
    if c.order() == 1:
        x_start = c.minD()
        for i in range(n - 1):
            X.append(x_start)
            Y.append(c.eval(x_start))
            x_start += step
    else:
        x_start = c.minD() + step
        for i in range(n - 2):
            X.append(x_start)
            Y.append(c.eval(x_start))
            x_start += step
    plt.plot(X, Y, color='green')
    plt.show()
