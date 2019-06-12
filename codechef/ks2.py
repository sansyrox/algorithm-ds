def roundNo(x):
    num = 19
    for i in range(0,x-1):
        num+=9
    
    return num
    


t = int(input())
while t>0:
    t-=1
    x = int(input())
    print(roundNo(x))