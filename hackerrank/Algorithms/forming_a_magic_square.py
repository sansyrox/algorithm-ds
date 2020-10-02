import sys

# This problem is available on https://www.hackerrank.com/challenges/magic-square-forming/problem


matrix_list = [[[8, 1, 6], [3, 5, 7], [4, 9, 2]],
               [[6, 1, 8], [7, 5, 3], [2, 9, 4]],
               [[4, 9, 2], [3, 5, 7], [8, 1, 6]],
               [[2, 9, 4], [7, 5, 3], [6, 1, 8]],
               [[8, 3, 4], [1, 5, 9], [6, 7, 2]],
               [[4, 3, 8], [9, 5, 1], [2, 7, 6]],
               [[6, 7, 2], [1, 5, 9], [8, 3, 4]],
               [[2, 7, 6], [9, 5, 1], [4, 3, 8]]]


# function for calculation of min cost
def get_min_cost(mat: list) -> int:
    cost_list = [sys.maxsize] * len(matrix_list)
    for ref_mat in matrix_list:
        cost = 0
        for x in range(0, len(mat)):
            for y in range(0, len(mat)):
                if mat[x][y] != ref_mat[x][y]:
                    cost += abs(mat[x][y] - ref_mat[x][y])
        cost_list.append(cost)
    return min(cost_list)


# s = [[4, 8, 2], [4, 5, 7], [6, 1, 6]]
# s = [[4, 4, 7], [3, 1, 5], [1, 7, 9]]
# s = [[7, 2, 9], [6, 6, 2], [5, 1, 2]]


s = []
for s_i in range(3):
    s_t = [int(s_temp) for s_temp in input().strip().split(' ')]
    s.append(s_t)
print(get_min_cost(s))