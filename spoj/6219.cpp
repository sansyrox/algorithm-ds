#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int editDistance(string a, string b, int i, int j){

    int dp[i+1][j+1];
    for(int i=0; i<=a.length(); i++){
        for(int j=0;j<=b.length(); j++) {
            if(i==0){
                dp[i][j] = j;
            }
            else if(j==0){
                dp[i][j] = i;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else {
                dp[i][j] = 1 + min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
            }
        }
    }


    return dp[a.length()][b.length()];


}

int main() {
    int t; cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int i = a.length(),j=b.length();
        cout<<editDistance(a,b,i,j)<<endl;
    }
    return 0;
}