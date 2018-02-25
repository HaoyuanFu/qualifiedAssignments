## @file SeqServices.py
#  @author Harry Fu
#  @brief Provides the Sequence Services
#  @date 2/14/2018


## @brief Determines if a given sequence is ascending
#  @details Determines if a given sequence if ascending
#           with the assumption: length of X must > 1
#  @param X The sequence
#  @return True if ascending otherwise False
def isAscending(X):
    for x_prev, x_next in zip(X, X[1:]):
        if x_prev > x_next:
            return False
    return True


## @brief Determines if a givenv alue is inside the range of a given sequence
#  @details Determines if a given value is inside the range of a given sequence
#           with the assumption: isAscending(X) is True
#  @param X The sequence
#  @param x The value
#  @return True if in-bound otherwise False
def isInBounds(X, x):
    return X[0] <= x <= X[-1]


## @brief Interpolates linearly a curve
#  @details Interpolates linearly a curve
#           with the assumption: x1 < x2
#           with the assumption: isInBounds([x1, x2], x)
#  @param x1 The x coordinate of the start point of the curve
#  @param y1 The y coordinate of the start point of the curve
#  @param x2 The x coordinate of the end point of the curve
#  @param y2 The y coordinate of the end point of the curve
#  @param x The value
#  @return The interpolated y value
def interpLin(x1, y1, x2, y2, x):
    return (y2 - y1) * (x - x1) / (x2 - x1) + y1


## @brief Interpolates quadratically a curve
#  @detals Interpolates quadratically a curve
#          with the assumption: x0 <= x1 < x2
#          with the assumption: isInBounds([x0, x1, x2], x)
#  @param x0 The x coordinate of the 1st point of the curve
#  @param y0 The y coordinate of the 1st point of the curve
#  @param x1 The x coordinate of the 2nd point of the curve
#  @param y1 The y coordinate of the 2nd point of the curve
#  @param x2 The x coordinate of the 3rd point of the curve
#  @param y2 The y coordinate of the 3rd point of the curve
#  @param x The x value
#  @return The interpolated y value
def interpQuad(x0, y0, x1, y1, x2, y2, x):
    return (
        y1 + (y2 - y0) * (x - x1) / (x2 - x0) +
        (y2 - 2 * y1 + y0) * ((x - x1) ** 2) / (2 * ((x2 - x1) ** 2))
    )


## @brief Finds the proximate index of the given value in the given sequence
#  @details Finds the index of the given value in the given sequence
#           with the assumption: isAscending(X) is True
#           with the assumption: isInBounds(X, x) is True
#           with the assumption: X[0] != X[-1]
#  @param X The sequence
#  @param x The value
#  @return The proximate index of x
def index(X, x):
    for i, (x_prev, x_next) in enumerate(zip(X, X[1:])):
        if x_prev <= x < x_next:
            return i
