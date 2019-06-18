#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

ll returnValue(ll n){
    ll dp[n+1];
    
    dp[0] =0, dp[1]=1;

    for(ll i=2; i<=n; i++){
        dp[i] = max(
            i,
            dp[i/2] + dp[i/3] + dp[i/4]
        );
    }

    return dp[n];
}


int main() {
    ll n; cin>>n;
    cout<<returnValue(n);
    return 0;
}