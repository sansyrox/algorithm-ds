#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[4001];

int rodCutting(int n, vector<int>& a){
    if(n==0){
        return 0;
    }

    if(dp[n]!=-1) return dp[n];

    int ans = INT_MIN;
    // cout<<n<<endl<<endl;
    for(int i=0; i<a.size(); i++){
        if(a[i]<=n)
            ans = max(ans, 1 + rodCutting(n-a[i],a));
    }

    return dp[n]=ans;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> ans;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<3; i++){
            int t; cin>>t;
            ans.push_back(t);
        }
        cout<<rodCutting(n,ans)<<endl;
    }
    return 0;
}