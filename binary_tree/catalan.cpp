#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[1001] = {0};

unsigned long int catalan(unsigned int n) 
{ 
    // Base case 
    if (n <= 1) return 1; 
  
    if(dp[n]!=0) return dp[n];
    // catalan(n) is sum of catalan(i)*catalan(n-i-1) 
    unsigned long int res = 0; 
    for (int i=0; i<n; i++) 
        res += catalan(i)*catalan(n-i-1); 
  
    return dp[n]=res; 
} 
  
// Driver program to test above function 
int main() 
{ 
    for (int i=0; i<10; i++) 
        cout << catalan(i) << " "; 
    return 0; 
}

