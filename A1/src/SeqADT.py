## @file SeqADT.py
#  @author Haoyuan(Harry) Fu
#  @brief Provides the SeqT ADT class for representing sequences
#  @date 1/22/2018


## @brief An ADT that represents a sequence
class SeqT:

    ## @brief SeqT constructor
    #  @details Initializes a SeqT object
    #  @param self The object pointer
    def __init__(self):
        self.seq = []

    ## @brief Adds a value into the sequence at the given index
    #  @details The value can only be added within the existing sequence
    #           or immediately after the last entry in the existing sequence
    #  @param self The object pointer
    #  @param i The index where the value should be added within the sequence
    #  @param v The value to be added to the sequence
    #  @exception IndexError raises for illegal index
    def add(self, i, v):
        if i < 0 or i > len(self.seq):
            raise IndexError('illegal index')
        self.seq.insert(i, v)

    ## @brief Removes a value from the sequence
    #  @details The index can only be within the existing sequence
    #  @param self The object pointer
    #  @param i The index where the value located in the sequence
    #  @exception IndexError raises for illegal index
    def rm(self, i):
        if i < 0 or i > len(self.seq) - 1:
            raise IndexError('illegal index')
        self.seq.pop(i)

    ## @brief Modifies a value at the given index of the sequence
    #  @details The index can only be within the existing sequence
    #  @param self The object pointer
    #  @param i The index where the value located in the sequence
    #  @param v The value used to replace the old one
    #  @exception IndexError raises for illegal index
    def set(self, i, v):
        if i < 0 or i > len(self.seq) - 1:
            raise IndexError('illegal index')
        self.seq[i] = v

    ## @brief Takes a value at the given index of the sequence
    #  @details The index can only be within the existing sequence
    #  @param self The object pointer
    #  @param i The index where the value located in the sequence
    #  @return The value at the given index of the sequence
    #  @exception IndexError raises for illegal index
    def get(self, i):
        if i < 0 or i > len(self.seq) - 1:
            raise IndexError('illegal index')
        return self.seq[i]

    ## @brief Retrieves the length of the sequence
    #  @param self The object pointer
    #  @return The length of the sequence
    def size(self):
        return len(self.seq)

    ## @brief Finds the index of the value approximately
    #  @details For the sequence object s, returns the index i
    #           such that s.get(i) <= v <= s.get(i+1)
    #  @param self The object pointer
    #  @param v The value to be found in the sequence
    #  @return The index of the value
    #  @exception ValueError raises for illegal value
    def indexInSeq(self, v):
        for i, _v_ in enumerate(self.seq[:-1]):
            if _v_ <= v and v <= self.seq[i + 1]:
                return i
        raise ValueError('illegal value')
