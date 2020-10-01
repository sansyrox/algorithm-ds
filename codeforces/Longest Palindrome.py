# This file contain the solution to the problem Codeforce Longest Palindrome 
# Problem NUmber: 1304B
# Link to the Problem: https://codeforces.com/problemset/problem/1304/B
a=input()
a=a.split()
n,m=[int(i) for i in a]
li=[]
p=[]
for i in range(n):
    x=input()
    if(x==x[::-1]):
        p.append(x)
    else:
        li.append(x)
result=[]
s=""
l=""
for j in li:
    if(j[::-1] in li):
        s=s+j
        l=j[::-1]+l
        li.pop(li.index(j[::-1]))
if (len(p)):
    print(len(s+p[0]+l))
    print(s+p[0]+l)
else:
    print(len(s+l))
    print(s+l)

