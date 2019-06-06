#include<iostream>
#include<bits/stdc++.h>
#include<bitset>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bitset<30> col,d1,d2;

void solve(int r, int n, int &ans){
    if(r==n) {ans+=1; return;}

    for(int c=0; c<n; c++){
        if( !col[c] && !d1[r-c+n-1] && d2[r+c]){
            col[c] = d2[r-c+n-1] = d2[r+c] = 1;
            solve(r+1,n,ans);
            col[c] = d2[r-c+n-1] = d2[r+c] = 0;
        }
    }
}

int main() {
    
    int n;
    cin>>n;
    int ans=0;
    solve(0,n,ans);
    cout<<ans;
    


    return 0;
}