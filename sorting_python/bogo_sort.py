# This file contains the Bogo Sort algorithm written in python.
# Attention: This sorting algorithm is for fun use only it can take up to infite iterations to sort an array with this algorithm
from helper_functions import isSorted
import random

# Input: Array to be sorted
# Output: Sorted array
def bogosort(arr):
        while not isSorted(arr):
                random.shuffle(arr)
        return arr