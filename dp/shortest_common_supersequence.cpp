#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[1001][1001];

int sLCS(string s1, string s2, int i, int j){
    if(i==0||j==0){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s1[i-1]==s2[j-1]){
        return dp[i][j] = 1 + sLCS(s1,s2,i-1,j-1);
    }

    return dp[i][j]=max(
        sLCS(s1,s2,i-1,j),
        sLCS(s1,s2,i,j-1)
    );
}

int main() {
    int t; cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        string s1,s2;
        cin>>s1>>s2;
        cout<<s1.length() + s2.length() - sLCS(s1,s2,s1.length(),s2.length())<<endl;
    }
    
    return 0;
}