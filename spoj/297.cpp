#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool isValid(ll arr[], ll n, ll ans, ll c){
    ll k=1;
    ll prev=arr[0];
    for(int i=0; i<n; i++){
        if(k==c){
            return true;
        }
        if(arr[i]-prev>=ans){
            k++;
            prev = arr[i];
        }
    }


    if(k==c){
            return true;
        }

    return false;


}

ll minDistance(ll arr[], ll n, ll c) {
    ll min = 0, max = arr[n-1];
    
    ll ans = 0;

    while(min<=max){
        ll mid = min + (max-min)/2;
            // cout<<mid<<endl;
        
        if(isValid(arr,n,mid,c)){

            ans = mid;
            min = mid+1;
        }
        else {
            max = mid-1;
        }
    }

    return ans;

}


int main() {
    ll t; cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        ll arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr,arr+n);

        cout<<minDistance(arr,n,c)<<endl;
    }
    return 0;
}