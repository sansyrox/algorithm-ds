# This file contains some helper functions to support sorting algorithms written in python.
import time
import random
from copy import deepcopy 

# Input: Size of the output array
# Output: Array with random numbers from lower_border to upper_border        
def randarr(size, lower_border, upper_border):
        l=[]
        for i in range(size):
                l.append(random.randint(lower_border, upper_border))
        return l

def isSorted(arr):
        for i in range(len(arr)):
                if not i==len(arr)-1:
                        if arr[i]>arr[i+1]:
                                return False
                elif arr[i]<arr[i-1]:
                        return False
        return True