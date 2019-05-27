#include<iostream>
using namespace std;

int dp[1000] = {}

int maxProfit(int arr[], int len){

    if(len==0) return 0;
    
    if(dp[len]!=-1) return dp[len];


    int maxProfit=0;
    
    for(int i=0; i<len; i++){
        int profit=arr[i] + maxProfit(arr,len-i);
        maxProfit=max(profit,maxProfit);
    }

    dp[len] = maxProfit;

    return dp[len];

}


int maxDP(int arr[], int len){
    dp[0]=arr[0];
    for(int i=1; i<=len; i++){
        for(int cut =1; cut<= i; ++cut){
            dp[len] = arr[cut] + dp[i-cut];
        }
    }

    return dp[len];


}


int main(){
    int n;
    cin>>n;
    int arr[100];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<maxProfit(arr,n);
    memset(dp,-1,sizeof(dp));

    
    return 0;
}
