import time
import random
from copy import deepcopy 
        
def randarr(size):
        l=[]
        for i in range(size):
                l.append(random.randint(-99,101))
        return l

def isSorted(arr):
        for i in range(len(arr)):
                if not i==len(arr)-1:
                        if arr[i]>arr[i+1]:
                                return False
                elif arr[i]<arr[i-1]:
                        return False
        return True