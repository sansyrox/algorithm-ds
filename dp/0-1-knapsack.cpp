#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[1001][1001];

int knapSack( int wt[],int price[], int N,int W ){
    if(N==0||W==0){
        return 0;
    }

    if(dp[N][W]!=-1) return dp[N][W];

    int incl=0,excl=0;

    if(wt[N-1]<=W){
        incl = price[N-1] + knapSack(wt,price,N-1,W-wt[N]);
    }
    excl = knapSack(wt,price,N-1,W);

    return dp[N][W]=max(incl, excl);
}

int bottomUp(int wt[], int price[], int N,int W){


    for(int i=0; i<N; i++){
        for(int j=0; j<=W; j++){
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else {
                int inc=0,exc=0;
                if(wt[i-1]<=W){
                    inc = price[i-1] + dp[i-1][j-1];
                }
                exc = dp[i-1][j];

                dp[i][j] = max(inc,exc);
            }
        }
    }

    return dp[N][W];
}


int main() {
    memset(dp,-1,sizeof(dp));
    // cout<<knapSack

    return 0;
}