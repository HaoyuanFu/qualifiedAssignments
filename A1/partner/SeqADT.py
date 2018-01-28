## @file SeqADT
#  @author Thomas Shang
#  @brief Provides the SeqT ADT class for representing curves
#  @date 1/22/2018


## @brief An ADT that represents a Sequence
class SeqT:

	## @brief SeqT constructor
	#  @details Initializes a SeqT object that contains an empty array
	def __init__(self):
		self.data = []


	## @brief Inserts or appends the value v based on the value i
	#  @details If the value of i is equivalent to the current size of the data array the value is appened.
	#           Otherwise if the value of i is within the indexes of the array the value is inserted at the value i.
	#			If the value i is neither of the above values the value is not inserted
	# @param i desired index for added value
	# @param v real number to be added
	def add(self, i, v):
		if(i == self.size()):
			self.data.append(v)
		elif(i < self.size()):
			out = self.data[:i];
			back = self.data[i:]
			out.append(v);
			out.extend(back)
			self.data = out
		else:
			print ("illegal index")

	## @brief Removes value from sequence at position i
	#  @param i index of value to be removed
	def rm(self, i):
		del self.data[i]

	## @brief Sets value of stored at index i to v
	# @param i index of value to be changed
	# @param v value of new value

	def set(self, i, v):
		self.data[i] = v

	## @brief Returns value stored at index i in sequence
	# @param i index of value to be returned
	# @return value stored in sequence at index i 
	def get(self, i):
		return self.data[i]

	## @brief Returns size of sequence
	# @return size of sequence
	def size(self):
		return len(self.data)


	## @brief Returns index value where v falls between the index value i and i + 1
	#  @param v real value
	#  @return index value of value v
	def indexInSeq(self , v):
		for i in range(self.size()-1):
			if(self.get(i) <= v and self.get(i+1) >= v):
				return i
		
		print("Value not within sequence")
