#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[1001][1001];

int subSetSum(vector<int> &sum_array,int totalSum, int sum=0, int i=0){

    if(i==sum_array.size()){
        int ans = abs(totalSum - 2*sum);
        return ans;
    }

    if(dp[i][sum]!=-1){
        return dp[i][sum];
    }

    return dp[i][sum] = min(subSetSum(sum_array,totalSum,sum,i+1),
    subSetSum(sum_array,totalSum,sum+sum_array[i],i+1));

}

// bottom Up dp
int findMin(int arr[], int n) 
{ 
    // Calculate sum of all elements 
    int sum = 0;  
    for (int i = 0; i < n; i++) 
        sum += arr[i]; 
  
    // Create an array to store results of subproblems 
    bool dp[n+1][sum+1]; 
  
    // Initialize first column as true. 0 sum is possible  
    // with all elements. 
    for (int i = 0; i <= n; i++) 
        dp[i][0] = true; 
  
    // Initialize top row, except dp[0][0], as false. With 
    // 0 elements, no other sum except 0 is possible 
    for (int i = 1; i <= sum; i++) 
        dp[0][i] = false; 
  
    // Fill the partition table in bottom up manner 
    for (int i=1; i<=n; i++) 
    { 
        for (int j=1; j<=sum; j++) 
        { 
            // If i'th element is excluded 
            dp[i][j] = dp[i-1][j]; 
  
            // If i'th element is included 
            if (arr[i-1] <= j) 
                dp[i][j] |= dp[i-1][j-arr[i-1]]; 
        } 
    } 
   
    // Initialize difference of two sums.  
    int diff = INT_MAX; 
      
    // Find the largest j such that dp[n][j] 
    // is true where j loops from sum/2 t0 0 
    for (int j=sum/2; j>=0; j--) 
    { 
        // Find the  
        if (dp[n][j] == true) 
        { 
            diff = sum-2*j; 
            break; 
        } 
    } 
    return diff; 
} 

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> sum_array;
        int total_sum = 0;
        for(int i=0; i<n; i++){
            int t; cin>>t;
            total_sum+=t;
            sum_array.pb(t);
        }
        // for(int i=0; i<101; i++) dp[i] = -1;
        memset(dp,-1,sizeof(dp));
        
        cout<<subSetSum(sum_array,total_sum, 0,0)<<endl;
    }
    return 0;
}