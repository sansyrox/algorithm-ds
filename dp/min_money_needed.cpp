#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[1001];
// n =w
int minPrice(int price[], int i,int n, int w){
    
    if(w==0) {
        return 0;
    }

    if(i>=n){
        return INT_MAX;
    }

    if(dp[w]!=-1) return dp[w];

    int minP = INT_MAX;
    if(price[i]!=-1){
        if(minPrice(price, i, n, w-i)!=INT_MAX)
            minP = min(minP,price[i] + minPrice(price, i+1, n, w-i));
    }

    minP = min(minP, minPrice(price, i+1, n, w-i));

    return dp[w]=minP;

}

int main() {
    int n,w;
    cin>>n>>w;
    int price[n+1];
    price[0]=-1;
    for(int i=1; i<=w; i++) cin>>price[i];
    memset(dp,-1,sizeof(dp));
    cout<<minPrice(price,0,w,w);
    return 0;
}