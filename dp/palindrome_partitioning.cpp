#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int isPalindrome(string s, int i , int j){
    while(i<=j){
        if(s[i++]!=s[j--]){
            return false;
        }
    }

    return true;
}

int dp[1001][1001];

int palindromePartitioning(string s, int i, int j){
    if(i>j){
        return INT_MAX;
    }

    if(i==j){
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    // cout<<s.substr(i,j)<<endl;

    if(isPalindrome(s,i,j)) {
        return 0;
    }

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++){
        // string s1 = s.substr(i,k);
        // string s2 = s.substr(k+1,j);

        int subAns= (1+ palindromePartitioning(s,i,k) + palindromePartitioning(s,i+1,j));
        ans = min(ans, subAns);
    }

    return dp[i][j]=ans;
}

int main() {
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        memset(dp,-1,sizeof(dp));
        cout<<palindromePartitioning(s,0,s.length()-1)<<endl;
    }
    return 0;
}