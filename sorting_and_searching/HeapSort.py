def parent(i):
    return (i-1) // 2


def right(i):
    return (i * 2) + 2


def left(i):
    return (i * 2) + 1


def heap_sort(nums):
    build_max_heap(nums)
    n = len(nums)
    for i in range(n - 1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        max_heapify(nums, 0)


def build_max_heap(nums):
    for i in range(len(nums) // 2, -1, -1):
        max_heapify(nums, i)


def max_heapify(nums, i):
    l = left(i)
    r = right(i)
    largest = -100000
    if l < len(nums) and nums[l] > nums[i]:
        largest = l
    else:
        largest = i

    if r < len(nums) and nums[r] > nums[largest]:
        largest = r

    if largest != i:
        nums[i], nums[largest] = nums[largest], nums[i]
        max_heapify(nums, largest)


if __name__ == "__main__":
    # nums = [9, 8, 7, 2, 4, 99, 20, 3, 4, 9, 8, 1]
    nums = [12, 11, 13, 5, 6, 7]
    heap_sort(nums)
    print(nums)
