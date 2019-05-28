#include<iostream>
using namespace std;

int dp[1001][1001];

int LCS(string s1,string s2,int i, int j){

    if(i>=s1.length() || j>=s2.length()){
        return 0;
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }

    if(s1[i]==s2[j]){
       return 1+LCS(s1,s2,i+1,j+1);
    }



    return dp[i][j]=max(LCS(s1,s2,i+1,j),LCS(s1,s2,i,j+1));


}


int main(){
    int t; cin>>t;

    while(t--){
        int a,b;
        cin>>a>>b;
        string s1,s2;
        cin>>s1>>s2;
        memset(dp,-1,sizeof(dp));
        cout<<LCS(s1,s2,0,0);
    }
    return 0;
}