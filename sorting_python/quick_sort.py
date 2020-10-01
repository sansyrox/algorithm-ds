# This file contains the Quick Sort algorithm written in python.
# Input: Array to be sorted
# Output: Sorted array
def quicksort(arr):
        left=[]
        right=[]
        same=[]
        if len(arr)>1:
                a=arr[0]
                for el in arr:
                        if el < a:
                                left.append(el)
                        elif el == a:
                                same.append(el)
                        elif el > a:
                                right.append(el)    
                return quicksort(left)+same+quicksort(right)   
        else:
                return arr