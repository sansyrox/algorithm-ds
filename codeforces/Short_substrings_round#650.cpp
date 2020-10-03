/*
The problem is a very popular one where we are dealing with 2 substrings a & b-

b is built from a as follows: write all the substrings of length 2 of the string a in the order from left to right, and then join them in the same order into the string b.

For example, if we come up with the string a="abac", then all the substrings of length 2 of the string a are: "ab", "ba", "ac". Therefore, the string b="abbaac".

Now, what the code does? We are given the string b and we have to find the parent string a. It can work on any number of test cases t. Given below are some test cases.
INPUT-
4
abbaac
ac
bccddaaf
zzzzzzzzzz
OUTPUT-
abac
ac
bcdaf
zzzzzz
*/


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
