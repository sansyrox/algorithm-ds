// Any programmer worth his salt would be familiar with the famous Longest Common Subsequence problem. Mancunian was asked to solve the same by an incompetent programmer. As expected, he solved it in a flash. To complicate matters, a twist was introduced in the problem.

// In addition to the two sequences, an additional parameter k was introduced. A k-ordered LCS is defined to be the LCS of two sequences if you are allowed to change at most k elements in the first sequence to any value you wish to. Can you help Mancunian solve this version of the classical problem?

// Input: 
// The first line contains three integers N, M and k, denoting the lengths of the first and second sequences and the value of the provided parameter respectively.
// The second line contains N integers denoting the elements of the first sequence.
// The third line contains M integers denoting the elements of the second sequence.

// Output:
// Print the answer in a new lin


#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[2008][2008][8];


ll lcs(ll a1[], ll a2[], int i, int j, int k){

    if(i<=0 or j<= 0) return 0;

    if(dp[i][j][k] != -1) return dp[i][j][k];

    if(a1[i-1]==a2[j-1]) {
        return dp[i][j][k]=1+lcs(a1,a2,i-1,j-1,k);
    }

    ll res=0;

    if(k>0) {
        res = 1 + lcs(a1,a2, i-1,j-1,k-1);
    }

    res = max (
        res,
        max(
        lcs(a1,a2, i-1,j,k),
        lcs(a1,a2, i,j-1,k)
        )
    );

    return dp[i][j][k]=res;
}


int main() {

    ll n,m,k;

    cin>>n>>m>>k;
    ll a1[n], a2[m];
    for(int i=0; i<n; i++){
        cin>>a1[i];
    }
    for(int i=0; i<m; i++){
        cin>>a2[i];
    }

    memset(dp,-1,sizeof(dp));

    cout<<lcs(a1,a2,n,m,k);
    return 0;
}