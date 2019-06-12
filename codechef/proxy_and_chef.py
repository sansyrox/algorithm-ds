
def numberOfSteps(s,d):
    cpy = s
    cnt=0
    for i in s:
        if(i=='P'):
            cnt+=1

    percent = (cnt/d)
    # print(percent)
    if percent >= 0.75:
        return 0
    
    steps=0
    for i in range(2,d-2):
        percent = (cnt/d)

        if(percent>=0.75):
            return steps
        
        if(cpy[i]=='A' and (s[i-1]=='P' or s[i-2]=='P') and (s[i+1]=='P' or s[i+2]=='P')):
            # cpy[i]='P'
            cnt+=1
            steps+=1
        
    return steps

x = int(input())
while x>0:
    x-=1
    d = int(input())
    s = input()
    print(numberOfSteps(s,d))