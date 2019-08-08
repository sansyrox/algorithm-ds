#include<stdio.h>
int dissect(int num)
{
    int ans=0;
    while(num)
    {
        int t=num%10;
        ans+=t*t;
        num/=10;
    }
    return ans;
}
int main()
{
    int num,count=0,hit=1;
    int arr[1000]={0};
    scanf("%d",&num);
    while(1)
    {
        int temp;
        temp=dissect(num);
        if(arr[temp]==0)
        {
            num=temp;
            arr[temp]=1;
            count++;
        }
        else{
            hit=0;
            break;}
        if(num==1)
            break;
    }
    if(hit)
        printf("%d\n",count);
    else
        printf("-1\n");
    return 0;
}