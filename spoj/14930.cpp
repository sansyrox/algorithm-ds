#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

ll maxCoins(ll arr[], ll n){
    ll dp[n+1];
    fill(dp,dp+(n+1),0);
    dp[0] = arr[0];
    dp[1] = max(arr[1],dp[0]);

    for(ll i=2; i<n; i++){
        dp[i] = max(dp[i-1], dp[i-2]+arr[i]);
    }

    return max(dp[n-1],dp[n-2]);
}

int main() {
    ll t; 
    cin>>t;
    for(ll i=1; i<=t; i++) {
        ll n; cin>>n;
        ll arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        if(n==0){
            cout<<"Case "<<i<<": "<<0<<endl;
        }
        else if(n==1){
            cout<<"Case "<<i<<": "<<arr[0]<<endl;
        }
        else
            cout<<"Case "<<i<<": "<<maxCoins(arr,n)<<endl;
    }
    return 0;
}