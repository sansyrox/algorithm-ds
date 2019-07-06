#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph {
    public:
        int v;
        list< pair<int, int> >*adj;

        Graph(int v){

        }

};

int main() {
    
    return 0;
}


// #define vvi vector<vector<int> >
// class Solution {
// public:
//     int minDominoRotations(vector<int>& A, vector<int>& B) {
//         vector<int> dp(A.size()+1,-1);
//         int ans = helper(A,B,dp,0);
        
//         if(ans==INT_MAX){
//             return -1;
//         }
        
//         return ans;
//     }
    
//     bool allEqual(vector<int> &A){
//         if(A.size()<=1){
//             return true;
//         }
//         for(int i=0; i<A.size()-1; i++){
//             if(A[i]!=A[i+1]){
//                 return false;
//             }
//         }
        
//         return true;
//     }
    
//     int helper(vector<int> &A, vector<int> &B,vector<int> &dp, int i=0){
        
//         int dp[A.size()+1];
        
//         for(int i=0; i<=A.size(); i++){
//             if(i==0){
//                 if(allEqual(A)||allEqual(B)){
//                 dp[i]=0;
//                 }
//                 else dp[i]=INT_MAX;
//             }else {
//                 if(A[i]==B[i]){
//                     dp[i] = dp[i-1];
//                 }
//                 else {
//                     int ans1 = dp[i-1];
//                     // int ans2 = dp[i-]
//                 }
//             }
//         }
        
        
        
//         int ans1 = helper(A,B,dp,i+1);
//         swap(A[i],B[i]);
//         int ans2 = helper(A,B,dp,i+1);
//         swap(A[i],B[i]);
        
//         if(ans1==INT_MAX and ans2==INT_MAX){
//             return INT_MAX;
//         }
//         else if(ans1==INT_MAX) {
//             return dp[i]=1 + ans2;
//         }
//         else if(ans2==INT_MAX) {
//             return dp[i]=ans1;
//         }
        
        
//         return dp[i]=min(ans1,1+ans2);
        
//     }
// };