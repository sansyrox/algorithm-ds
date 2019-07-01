#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[4001];

int rodCutting(int n, int arr[]){

    if(n==0){
        return 0;
    }

    if(n<0){
        return INT_MIN;
    }

    if(dp[n]!=-1){
        return dp[n];
    }

    int ans = 1 + max(rodCutting(n-arr[0],arr),max(
        rodCutting(n-arr[1],arr),
        rodCutting(n-arr[2], arr)
    ));

    return dp[n]=(ans);
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[3];
        cin>>arr[0]>>arr[1]>>arr[2];
        fill(dp,dp+n, -1);
        // for(int i=0; i<n; i++) cout<<dp[i]<<" ";
        // cout<<endl;
        cout<<rodCutting(n,arr)<<endl;
    }
    return 0;
}

// #include <iostream>
// #include <cstring>
// using namespace std;

// int DP[4001];
// int X, Y, Z;
// int Get_Max(int N)
// {
//   if(N==0) return 0;
//   if(N<0) return __INT_MAX__*-1;

//   if(DP[N]!=-1) return DP[N];
//   return DP[N]=1+std::max(Get_Max(N-X), std::max(Get_Max(N-Y), Get_Max(N-Z)));
// }

// int main()
// {
//   int T, N;
//   cin>>T;

//   while(T--)
//   {
//     memset(DP, -1, sizeof(DP));
//     cin>>N>>X>>Y>>Z;
//     cout<<Get_Max(N)<<endl;
//   }
// }