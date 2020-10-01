def bubble_sort(nums):
    for i in range(len(nums)):
        for j in range(len(nums)):
            if nums[j] > nums[i]:
                nums[i], nums[j] = nums[j], nums[i]


if __name__ == "__main__":
    nums = [5, 2, 4, 6, 1, 3]
    bubble_sort(nums)
    print(nums)
