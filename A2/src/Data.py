## @file Data.py
#  @author Harry Fu
#  @brief Provides the Data manipulation methods
#  @detals Provides the Data manipulation methods with the assumption:
#          Data init() is called before any other access program.
#  @date 2/14/2018

from CurveADT import CurveT
from SeqServices import *
from Exceptions import *


## @brief An class of data manipulation methods
class Data:
    MAX_SIZE = 10

    # sequence of CurveT
    S = []
    # sequence of value
    Z = []

    ## @brief Initializes data module
    @staticmethod
    def init():
        Data.S, Data.Z = [], []

    ## @brief Adds a curve-value pair
    #  @param s The curve component
    #  @param z The value component
    #  @exception Full raises for already-full sequence
    #  @exception IndepVarNotAscending raises for illegal z value
    @staticmethod
    def add(s, z):
        if len(Data.S) == Data.MAX_SIZE:
            raise Full('{} {}'.format(Data.S, Data.MAX_SIZE))
        if len(Data.Z) > 0 and z <= Data.Z[-1]:
            raise IndepVarNotAscending(Data.Z)
        Data.S.extend([s])
        Data.Z.extend([z])


    ## @brief Gets a curve
    #  @param i The index of curve
    #  @return The fetched curve
    #  @exception InvalidIndex raises for illegal index
    @staticmethod
    def getC(i):
        if not 0 <= i < len(Data.S):
            raise InvalidIndex(0, i, len(Data.S))
        return Data.S[i]

    ## @brief Evaluates y value using the given x value and z value
    #  @exception OutOfDomain raises for illegal value
    @staticmethod
    def eval(x, z):
        if not isInBounds(Data.Z, z):
            raise OutOfDomain(Data.Z[0], z, Data.Z[-1])
        j = index(Data.Z, z)
        return interpLin(Data.Z[j], Data.S[j].eval(x), Data.Z[j + 1], Data.S[j + 1].eval(x), z)


    ## @brief Slices the curves
    #  @param x The x value
    #  @param i The order
    #  @return The sliced Curve
    @staticmethod
    def slice(x, i):
        return CurveT(Data.Z, [s.eval(x) for s in Data.S], i)
