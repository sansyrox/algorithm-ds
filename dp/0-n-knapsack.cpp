#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

// put n here
int dp[1001][1001];
int knapSack(int wt[], int val[], int w, int n){
    if(n==0 or w==0){
        return dp[n][w] = 0;
    }

    if(dp[n][w]!=-1) return dp[n][w];

    int inc = 0, exc=0;
    if(wt[n-1]<=w){

        inc = max(val[n-1] + knapSack(wt,val,w-wt[n-1],n) ,val[n-1] + knapSack(wt,val,w-wt[n-1], n-1));
    }

    exc= knapSack(wt,val,w,n-1);

    return dp[n][w] = max(inc,exc);


}


int main() {
    int n,k;
    cin>>n>>k;
    int val[n],wt[n];
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<n;i++) cin>>wt[i];
    for(int i=0; i<n;i++) cin>>val[i];

    cout<<knapSack(wt,val,k,n);
    return 0;
}