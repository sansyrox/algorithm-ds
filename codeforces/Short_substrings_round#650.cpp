#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int t;
cin>>t;
while(t--)
{
long long int count=0;
string s;
cin>>s;
int n=s.length();
char arr[n+1];
strcpy(arr, s.c_str());
for(int i=1; i<n; i++)
{
if(arr[i]==arr[i+1])
{
count++;
i++;
}
else
count++;
}
char b[count];
b[0]=arr[0];
long long int j=1;
for(int i=1; i<n; i++)
{
if(arr[i]==arr[i+1])
{
b[j]=arr[i];
i++;
 
}
else
{
b[j]=arr[i];
}
j++;
}
for(int i=0; i<count+1; i++)
{
cout<<b[i];
}
cout<<endl;
}
}
