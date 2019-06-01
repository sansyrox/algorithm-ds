#include<iostream>
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
using namespace std;

//input n-1
bool checkBitonic(ll arr[],ll i,ll n){
    bool increasing = true;

    for(; i<n-1; ++i){
        if(arr[i]>arr[i+1]) {
            increasing = false;
            break;
        }
    }

    if(i==n-1){
        if(arr[n-2]<arr[n-1]) return true;
    }

    for(; i<n-1; ++i) {
        if(arr[i]<arr[i+1] and !increasing){
            return false;
        }
    }

    return true;

}

ll maxLengthBitonicSubarry(ll arr[],ll n) {
    vector<pair<ll,ll> > v;

    for(ll i=0; i<n; i++) {
        for(ll j=i; j<n; j++) {
            v.push_back(make_pair(i,j));
        }
    }
    // for(auto i:v) {
    //     cout<<i.first<<","<<i.second<<"\n";
    // }

    ll maxLength =0;

    for(auto i:v){
        if(checkBitonic(arr, i.first, i.second)) {
            ll maxLen = i.second - i.first + 1;
            maxLength = max(maxLength, maxLen);
        }
    }

    return maxLength;
} 

int main() {
   
   ll t;
   cin>>t;
   while(t--) {
       ll n;
       cin>>n;
       ll arr[n];
       for(ll i=0; i<n; i++){
           cin>>arr[i];
        }

        cout<<maxLengthBitonicSubarry(arr,n)<<endl;
   }

    return 0;
}