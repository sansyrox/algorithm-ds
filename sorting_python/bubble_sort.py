# This file contains the Bubble Sort algorithm written in python.
# Input: Array to be sorted
# Output: Sorted array
def bubblesort(arr):
    for j in range(len(arr)-1):
        for i in range(len(arr)-1):
            while arr[i]>arr[i+1]:
                arr[i], arr[i+1]=arr[i+1],arr[i]
    return arr   