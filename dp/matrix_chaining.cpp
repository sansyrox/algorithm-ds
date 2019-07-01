#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[101][101];

int matrixMultiplication(int arr[], int i, int j){
    if(i==j){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int ans = 0;
    for(int k=i; k<=j; k++){
        int subAns = matrixMultiplication(arr,i,k) + matrixMultiplication(arr,k+1,j) + arr[i-1]*arr[k]*arr[j];
        ans = min(ans,subAns);
    }

    return dp[i][j]=ans;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        memset(dp,-1,sizeof(dp));
        cout<<matrixMultiplication(arr,1,n-1)<<endl;
    }
    return 0;
}