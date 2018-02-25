## @file Load.py
#  @author Harry Fu
#  @brief Provides the Plotting methods
#  @details Provides the Plotting methods with the assumption:
#           The input file will match the given specification.
#  @date 2/14/2018

from Data import Data
from CurveADT import CurveT


## @brief Reads data from file
#  @param s The filename of file
def Load(s):
    Data.init()
    with open(s, 'r') as f:
        row = next(f)
        row = list(map(float, row.split(',')))
        Z = row
        n = len(Z)
        row = next(f)
        row = list(map(int, row.split(',')))
        O = row
        X_Y = [[] for _ in range(n + n)]
        for row in f:
            row = [e.strip() for e in row.split(',')]
            for i, e in enumerate(row):
                if e:
                    X_Y[i].append(float(e))
        for i, o in enumerate(O):
            Data.add(CurveT(X_Y[i + i], X_Y[i + i + 1], o), Z[i])
