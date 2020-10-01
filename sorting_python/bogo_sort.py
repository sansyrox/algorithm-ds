from helper_functions import isSorted
import random

def bogosort(arr):
        while not isSorted(arr):
                random.shuffle(arr)
        return arr