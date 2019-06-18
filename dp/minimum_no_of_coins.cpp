#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[1001];

int minCoins(int coins[],int n, int v){
    
    if(v==0){
        return 0;
    }

    if(dp[v]!=-1) return dp[v];

    int ans=INT_MAX; 
    for(int i=0; i<n; i++){
        if(coins[i]<=v){
            int subAns = minCoins(coins, n, v-coins[i]);
            if(subAns!=INT_MAX){
                ans = min(ans,subAns+1);
            }
        }

    }

    return dp[v]=ans;
}


int main() {
    int t; cin>>t;
    while(t--){
        int v,n;
        cin>>v>>n;
        int coins[n];
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++) cin>>coins[i];
        cout<<minCoins(coins,n,v)<<endl;
    }
    return 0;
}