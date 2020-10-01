#include<bits/stdc++.h>
using namespace std;

int foo(int n,int a,int b,int c,int arr[])
{
    if(n==0)
    {
        return(0);
    }
    if(n<0)
    {
        return(INT_MIN);
    }
    if(arr[n]!=-1)
    {
        return(arr[n]);
    }


    return arr[n]=(1+max(foo(n-a,a,b,c,arr),max(foo(n-b,a,b,c,arr),foo(n-c,a,b,c,arr))));
}
int main()
{
   int n,a,b,c;
   cin>>n>>a>>b>>c;
   int arr[n+1];
  
   for (int i = 0; i<=n; i++)
   {
       arr[i]=-1;
   }

   

   cout<<foo(n,a,b,c,arr)<<endl;
   

}