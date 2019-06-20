#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

// int dp[10000001][10000001];

bool subSetGen(int a[], int i, int k, int n){

    if(k==0){
        return true;
    }

    if(i==n){
        return false;
    }


    return subSetGen(a,i+1,k,n) or subSetGen(a,i+1,k - (a[i]),n);
    
}

bool subSetGen1(int a[], int k, int n){

    bool dp[n+1][k+1];

    for (int i = 0; i <= n; i++) 
      dp[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= k; i++) 
      dp[0][i] = false; 

    for(int i=1; i<=n; i++){
        for(int j=1; j<=k; j++){
            // if(i==0 or j==0) dp[i][j] = 0;
            if(a[i-1]>k){
                dp[i][j] = dp[i-1][j];
            }
            else {
                if(j-a[i-1] >= 0)
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-a[i-1]];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][k];

}


int main() {
    // memset(dp,-1,sizeof(dp));
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    subSetGen1(arr,s,n)==true ? cout<<"Yes":cout<<"No";
    
    return 0;
}