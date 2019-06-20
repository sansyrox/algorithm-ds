#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[1001];

int minJumps(int arr[], int n, int i=0){

    if(i>n) return INT_MAX;

    if(i==n){
        return 0;
    }

    if(dp[i]!=-1) return dp[i];

    int ans = INT_MAX;

    for(int j=1; j<=arr[i]; j++){
        if(minJumps(arr,n,i+j)!=INT_MAX)
            ans = min(ans, 1 + minJumps(arr,n,i+j));
    }

    return dp[i] = ans;
}


int main() {
    int t; cin>>t;
    while(t--){
        int n; 
        cin>>n;
        memset(dp, -1, sizeof(dp));
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<minJumps(arr,n,0)<<endl;
    }    
    return 0;
}