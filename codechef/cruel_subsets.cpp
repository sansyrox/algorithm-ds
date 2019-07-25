#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
int subsetPairNotDivisibleByK(int arr[], int N, 
                                         int K) 
{ 
    // Array for storing frequency of modulo 
    // values 
    int f[K]; 
    memset(f, 0, sizeof(f)); 
  
    // Fill frequency array with values modulo K 
    for (int i = 0; i < N; i++) 
        f[arr[i] % K]++; 
  
    //  if K is even, then update f[K/2] 
    if (K % 2 == 0) 
        f[K/2] = min(f[K/2], 1); 
  
    // Initialize result by minimum of 1 or 
    // count of numbers giving remainder 0 
    int res = min(f[0], 1); 
  
    // Choose maximum of count of numbers 
    // giving remainder i or K-i 
    for (int i = 1; i <= K/2; i++) 
        res += max(f[i], f[K-i]); 
  
    return res; 
}

int main() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n; i++) cin>>arr[i];

    cout<<subsetPairNotDivisibleByK(arr,n,k);
    return 0;
}