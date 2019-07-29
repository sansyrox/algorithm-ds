#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll sum=0;
        for(ll i=0; i<n; i++){
            ll t; cin>>t;
            sum = ((sum%n)+(t%n))%n;
        }

        if(!sum) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}