#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void normalSieve(ll high, vector<ll> &sieve){
    vector<bool> ans(high+1,false);

    for(int i=2; i<=high; i++){
                // cout<<"Idhar";
            if(!ans[i]){
                sieve.push_back(i);
                // cout<<i;
                for(int j=i; j<=high; j+=i){
                    ans[j] = true;
                }
            }
    }
}

void segmentedSieve(ll a, ll b){
    ll high = max(a,b);
    ll low = min(a,b);
    vector<ll> sieve;
    ll limit = sqrt(high);
    normalSieve(limit,sieve);

    ll n = high - low + 1;
    bool mark[n+1];
    fill(mark, mark + n+1, false);
    for(ll i=0; i<sieve.size(); i++) {
        ll loLim = floor(low/sieve[i]) * sieve[i];

        if(loLim < sieve[i]){
            loLim+=sieve[i];
        }
        if(loLim==sieve[i]){
            loLim+=sieve[i];
        }


        for(ll j = loLim; j<=high; j+=sieve[i]){
            mark[j-low] = true;
        }
    }

    for(ll i=low; i<=high; i++){
        if(!mark[i-low] and i!=1) {
            cout<<(i)<<endl;
        }
    }
}


int main() {
    ll t; cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        segmentedSieve(a,b);
        cout<<endl;

    }
    return 0;
}