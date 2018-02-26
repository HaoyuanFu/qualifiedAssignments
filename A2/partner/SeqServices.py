## @file SeqServices.py
#  @author Kajoban Kuhaparan
#  @brief Provides services for curve objects
#  @date 20/02/2018

## @brief Confirms whether a range of independant values are increasing
#  @param X A sequence of independant values
#  @return False if the values are not ascending
#  @return True if the values are ascending
def isAscending(X):

    for i in range(0, len(X) - 2):
        if X[i+1] < X[i]:
             return False
        return True 

## @brief Confirms whether a value is in the bounds of some range
#  @detials Assumes that isAscending is true
#  @param X A sequence that represents a range of values
#  @param x A value to be within the range
#  @return True if the specified value falls in the range
#  @return False if the specified value does not fall in the range 
def isInBounds(X, x):

    return (X[0] <= x) and (x <= X[len(X) - 1]) 

## @brief Returns the evaluation of a linear interpolation function
#  @detials Assumes that isAscending is true
#  @param x1 The value corresponding to the x value on the left of the pivot
#  @param y1 The value corresponding to the y value on the left of the pivot
#  @param x2 The value corresponding to the x value on the right of the pivot
#  @param y2 The value corresponding to the y value on the right of the pivot
#  @param x The pivot value in which the interpolation is being done around
#  @return ( ( ( (y2 - y1) / (x2 - x1) )*(x - x1) ) + y1 )
#          The evaluation of the linear interpolation using the given values 
def interpLin(x1, y1, x2, y2, x):

    return ( ( ( (y2 - y1) / (x2 - x1) )*(x - x1) ) + y1 )

## @brief Returns the evaluation of a quadratic interpolation function
#  @detials Assumes that isAscending is true
#  @param x0 The value corresponding to the x value on the left of the pivot
#  @param y0 The value corresponding to the y value on the left of the pivot
#  @param x1 The value corresponding to the first x value on the right of the pivot
#  @param y1 The value corresponding to the first y value on the right of the pivot
#  @param x2 The value corresponding to the second x value on the right of the pivot
#  @param y2 The value corresponding to the second y value of the right of the pivot
#  @param x The pivot value in which the interpolation is being done around
#  @return (y1 + ( ((y2 - y0)/(x2 -x0) )*(x - x1)) + (((y2 - 2*y1 + y0)/(2*((x2 - x1)**2)))*((x - x1)**2)) )
#          The evaluation of the quadratic interpolation using the given values
def interpQuad(x0, y0, x1, y1, x2, y2, x):

    return (y1 + ( ((y2 - y0)/(x2 -x0) )*(x - x1)) + (((y2 - 2*y1 + y0)/(2*((x2 - x1)**2)))*((x - x1)**2)) )

## @brief Returns the index such that the specified value falls between two values in ascending order
#  @detials Assumes that isAscending and isInBounds are true
#  @param X A sequence that represents a range of independant values
#  @param x A value that should fall in the range
#  @return i The index such that the value x falls between its neighboring values in ascending order
def index(X, x):
    
    for i in range(0, len(X) - 1):
        if X[i] <= x and x <= X[i+1]:
            return i

