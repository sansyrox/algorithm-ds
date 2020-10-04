# Project Euler  -  Question 1  -  Multiples of 3 & 5

# If we list all the natural numbers below 10 that are
#  multiples of 3 or 5, we get 3, 5, 6 and 9.
#  The sum of these multiples is 23.  Find the sum of
#  all the multiples of 3 or 5 below 1000.
#  ANSWER = 2318.

# Iterate i from 0 to 99
# If i is divisible by 3 or 5, add to sum

ans = 0
for i in range(100):
    if i % 3 == 0 or i % 5 == 0:
        ans += i

# Print answer
print('The sum is: ' + str(ans))
