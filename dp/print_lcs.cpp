#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

string dp[1001][1001];

string print_lcs(string a, string b, int i,int j, string o=""){
    
    if(dp[i][j]!=" "){
        return dp[i][j];
    }
    
    if(i==a.size() or j==b.size()){
        return o;
    }


    if(a[i]==b[j]){
        // cout<<a[i]<<endl;
        o.push_back(a[i]);
        return print_lcs(a,b,i+1,j+1,o);
    }

    string x = print_lcs(a,b,i+1,j,o);
    string y = print_lcs(a,b,i,j+1,o);

   return dp[i][j] = x.length()>y.length() ?  x: y;
}

int main() {
    for(int i=0; i<1001; i++){
        for(int j=0; j<1001; j++){
            dp[i][j] = " 3";
        }
    }
    string a,b;
    cin>>a>>b;
    cout<<print_lcs(a,b,0,0);

    return 0;
}