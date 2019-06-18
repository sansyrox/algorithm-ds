#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[102][102][102];

int lcs3(string a,string b, string c, int i=0, int j=0, int k=0){
    if(i==a.size() or j==b.size() or k==c.size()){
        return dp[i][j][k] = 0;
    }


    if(dp[i][j][k]!=-1) return dp[i][j][k];

    // base case only when all equal
    if(a[i]==b[j] and b[j]==c[k]){
        return dp[i][j][k] = 1 + lcs3(a,b,c,i+1,j+1,k+1);
    }
    
    
    return dp[i][j][k] = max(
        lcs3(a,b,c,i+1,j,k),
        max(
            lcs3(a,b,c,i,j,k+1),
            lcs3(a,b,c,i,j+1,k)
        )
    );

}

int lcs31(string a, string b, string c){
    int n=a.length(),m=b.length(),o=c.length();

    int dp[n+1][m+1][o+1];

    // if(i==0 or j==0 or k==0) {dp[i][j][k] = 0; continue;}

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            for(int k=0; k<=o; k++){
                if(i==0 or j==0 or k==0) {dp[i][j][k] = 0; continue;}
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            for(int k=1; k<=o; k++){
                if(i==0 or j==0 or k==0) {dp[i][j][k] = 0; continue;}
                if(a[i-1]==b[j-1] and b[j-1]==c[k-1]){
                    dp[i][j][k] = 1 + dp[i-1][j-1][k-1];
                    continue;
                }
                else 
                    dp[i][j][k] = max(
                        dp[i-1][j][k],
                        max(
                            dp[i][j][k-1],
                            dp[i][j-1][k]
                        )
                    );


            }
        }
    }


    return dp[n][m][o];
}


int main() {
    int t=1;
    while(t--){
    // int x,y,z;
    // cin>>x>>y>>z;
    string a,b,c;
    cin>>a>>b>>c;
    // memset(dp,-1,sizeof(dp));
    cout<<lcs31(a,b,c)<<endl;
    }
    return 0;
}