## @file Exceptions.py
#  @author Harry Fu
#  @brief Provides custom exceptions
#  @date 2/14/2018


## @brief An exception class for 'Independant Variable Not Ascending'
class IndepVarNotAscending(Exception):
    def __init__(self, *vals):
        self.vals = vals

    def __str__(self):
        return str(self.vals)


## @brief An exception class for 'Sequence Size Mismatch'
class SeqSizeMismatch(Exception):
    def __init__(self, *vals):
        self.vals = vals

    def __str__(self):
        return str(self.vals)


## @brief An exception class for 'Invalid Interpolation Order'
class InvalidInterpOrder(Exception):
    def __init__(self, *vals):
        self.vals = vals

    def __str__(self):
        return str(self.vals)


## @brief An exception class for 'Out of Domain'
class OutOfDomain(Exception):
    def __init__(self, *vals):
        self.vals = vals

    def __str__(self):
        return str(self.vals)


## @brief an exception class for 'Full'
class Full(Exception):
    def __init__(self, *vals):
        self.vals = vals

    def __str__(self):
        return str(self.vals)


## @brief an exception class for 'Invalid Index'
class InvalidIndex(Exception):
    def __init__(self, *vals):
        self.vals = vals

    def __str__(self):
        return str(self.vals)
