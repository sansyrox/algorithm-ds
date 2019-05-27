#include<iostream>
// #include<bits/stdc++.h>

using namespace std;

int dp[10001];

int fib(int n){

if(n==0|n==1) return n;

if(dp[n]!=-1) return dp[n];

int ans = fib(n-1) + fib(n-2);
dp[n] = ans;
return dp[n];


}

int main(){

    int n; cin>>n;
    for(int i=0; i<=n; i++){
        dp[i] = -1;
    }
    cout<<fib(n);

    return 0;
}
