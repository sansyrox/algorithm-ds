import sys

# This question is available on https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

if __name__ == "__main__":
    n = int(input().strip())
    scores = sorted(list(set(list(map(int, input().strip().split(' '))))), reverse=True)
    m = int(input().strip())
    alice = list(map(int, input().strip().split(' ')))
    scores.append(0)
    l = len(scores)
   
   
    # Write Your Code Here (solution)
    for a in alice:
        while (l > 0) and (a >= scores[l-1]):
            l -= 1
        print(l+1)                 
        