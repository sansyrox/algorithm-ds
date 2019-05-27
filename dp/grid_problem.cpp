#include<iostream>
using namespace std;
int dp[1001][1001];

int minCost(int arr[][3], int n){
    dp[n-1][n-1]=arr[n-1][n-1];

    dp[n-1][n-2] = arr[n-1][n-2];
    dp[n-2][n-1] = arr[n-2][n-1];

    // filling the rightmost and bottom most row
    for(int i=n-2; i>=0; i--){
        dp[i][n-1] += dp[i+1][n-1];
    }

    for(int i=n-2; i>=0; i--){
        dp[n-1][i] += dp[n-1][i+1];
    }

    for(int i=n-2; i>=0; i--){
        for (int j = n-2;j >=0; j--) {
            dp[i][j] = arr[i][j] + min(dp[i+1][j],dp[i][j+1]);
        }
    }

    for (int i = 0; i < n; i++) {
        for(int j=0; j< n; j++){
            cout<<dp[i][j]<<" ";
        }cout<<endl;
    }
    

    return dp[0][0];

}


int main(){

    int arr[3][3] = {
        1,2,3,
        4,8,2,
        1,5,3
    };


    // memset(dp,-1,sizeof(dp));
    cout<<minCost(arr,3);

    return 0;

}