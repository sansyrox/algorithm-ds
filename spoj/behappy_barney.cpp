#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

// int barneyAns(vector<int>&a, vector<int>& b, int m, int n){
//     if(m==0 and n==0){
//         return 1;
//     }

//     if(m==0){
//         return 0;
//     }

//     if(n==0){
//         return 0;
//     }



//     int minNumber = a[m-1], maxNumber = b[m-1];
//     // cout<<minNumber<<"  "<<maxNumber<<endl;
//     // exit(0);
//     int ans=0;

//     for(int i=minNumber; i<=maxNumber; i++) {
//         if(i<=n){
//             ans+=barneyAns(a,b,m-1,n-i);
//             // n=+i;
//             // cout<<ans<<endl;
//         }
//     }

//     return ans;

// }

int m,n;
int dp[21][101];
int barneyAns(vector<int>& a, vector<int>&b, int i=0, int j=n){
    if(i==m){
        if(j==0) return 1;
        return 0;
    }

    if(dp[i][j]!=-1) return dp[i][j];

    int ans =0;
    for(int x=a[i]; x<=b[i]; x++){
        if(j-x>=0){
            ans+=barneyAns(a,b,i+1,j-x);
        }
    }
    return dp[i][j]=ans;
}


int main() {
    int t=1;
    while(t--){
        cin>>m>>n;
        memset(dp,-1,sizeof(dp));
        int a,b;
        cin>>a>>b;
        vector<int> min1,max1;
        // cout<<"Hello"<<a<<b<<endl;
        while(a||b){
            min1.pb(a);
            max1.pb(b);
            cin>>a>>b;
        }

        cout<<barneyAns(min1,max1,0,n)<<endl;

    }
    return 0;
}