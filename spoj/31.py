t = int(input())
while (t):
    x = input()
    x = x.strip().split()
    x = list(map(int, x))

    print(x[0]*x[1])

    t-=1

