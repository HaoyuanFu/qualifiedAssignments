## @file Data.py
#  @author Kajoban Kuhaparan
#  @brief Provides a Data class for handling input
#  @date 20/02/2018

import CurveADT
import Exceptions
import SeqServices 

## @brief A Data object to store and manipulate data 
class Data:

    MAX_SIZE = 10

    ## @brief Data constructor
    #  @details Initializes a data object that initially has an empty
    #           sequence of curves and an empty seequence of special values. 
    def init():

        Data.S = []
        Data.Z = [] 

    ## @brief Adds curves and special values to their specified sequences 
    #  @details Ensures that the sequences are not full and that the special values are increasing
    #  @param s A curve to be added
    #  @param z A special value to be added 
    def add(s, z):

        if len(Data.S) == Data.MAX_SIZE:
            raise Exceptions.Full("Sequence is full")

        elif len(Data.Z) > 0 and z <= Data.Z[len(Data.Z) - 1]:
            raise Exceptions.IndepVarNotAscending("Independant variable not ascending")

        Data.S.append(s)
        Data.Z.append(z)

    ## @brief Accesses a curve given an index
    #  @details Ensures that the index is in the range required 
    #  @param i The index which the curve will be accessed from 
    #  @return The curve at the specified index 
    def getC(i):

        if i not in range(0, len(Data.S)):
            raise Exceptions.InvalidIndex("Index is not within range") 

        return Data.S[i]

    ## @brief Calculates the linear interpolation given an index of a special value and value in a curve
    #  @details Ensures that the index is in the range required 
    #  @param x The value on the curve
    #  @param z The index of the special value
    #  @return SeqServices.interpLin(Data.Z[j], Data.S[j].eval(x), Data.Z[j+1], Data.S[j+1].eval(x), z)
    #           The linear interpolation at the given values 
    def eval(x, z):

        if (not SeqServices.isInBounds(Data.Z, z)):
            raise Exceptions.OutOfDomain("Z value is out of domain") 

        j = SeqServices.index(Data.Z,z)

        return SeqServices.interpLin(Data.Z[j], Data.S[j].eval(x), Data.Z[j+1], Data.S[j+1].eval(x), z)  

    ## @brief Calculates the data slice given an x value and returns the slice in the form of a curve
    #  @param x The x value the slice will be taken at
    #  @param i The order of the interpolation used to construct the curve 
    #  @return CurveT(Data.Z, Y, i) The curve representation of the data slice
    def slice(x, i): 

        Y = [Data.S[s].eval(x) for s in range(0,len(Data.Z))]
        return CurveADT.CurveT(Data.Z, Y, i)

