#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back




// bool partitionProblem(int arr[],bool dp[101][10001], int n,int totalSum,int i=0, int currSum=0){
//     if(i==n){
//         return currSum == (totalSum-currSum);
//     }

//     // if(dp[i]!='-'){
//     //     return (bool)(dp[i]-'0');
//     // }

//     return (partitionProblem(arr,n,totalSum,i+1,currSum) || partitionProblem(arr,n,totalSum,i+1,currSum+arr[i]));
    
// }


bool partitionProblem(int arr[], int n){
    if(i==n){
        return currSum == (totalSum-currSum);
    }

    // if(dp[i]!='-'){
    //     return (bool)(dp[i]-'0');
    // }

    return (partitionProblem(arr,n,totalSum,i+1,currSum) || partitionProblem(arr,n,totalSum,i+1,currSum+arr[i]));
    
}

int main() {
    
    int t; cin>>t;
    while(t--){
        // for(int i=0; i<1001; i++) dp[i]='-';
        int n;cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int totalSum = 0;
        for(auto i:arr) totalSum += i;
        
        cout<<partitionProblem(arr,n,totalSum)<<endl;
    }
    

    return 0;
}