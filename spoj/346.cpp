#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

unordered_map<ll,ll> dp;
ll ans(ll x){
    if(x==0||x==1){
        return x;
    }

    // if(dp[x]!=-1){
    //     return dp[x];
    // }
    if(dp[x]) return dp[x];

    return dp[x]=max(x, ans(x/2) + ans(x/3) + ans(x/4));
}

int main() {
    ll x;
    while(cin>>x){
        // vector<ll> dp(x+1,-1);
        dp.clear();
        cout<<ans(x)<<endl;
    }
    return 0;
}