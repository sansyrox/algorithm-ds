#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int men[n],wam[n];
        for(int i=0; i<n; i++) cin>>men[i];
        for(int i=0; i<n; i++) cin>>wam[i];

        sort(men,men+n);
        sort(wam,wam+n);

        int ans=0;
        for(int i=0; i<n; i++) ans+=(men[i]*wam[i]);
        cout<<ans<<endl;
    }
    return 0;
}