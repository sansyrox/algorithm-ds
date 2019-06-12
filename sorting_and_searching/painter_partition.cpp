#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

const int mno = 10000003;

bool isValid(ll arr[], ll n, ll k, ll ans){
    ll count =1; // count of painters
    ll sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
        if(sum>ans){
            count++;
            sum=arr[i];
        }
        
    }

    if(count>k){
        return false;
    }
    return true;

}

ll minTime(ll arr[], ll n, ll k) {
    ll s=arr[n-1];
    ll e=0;
    for(ll i=0;i<n; i++){
        e+=arr[i];
    }

    ll ans;
    while(s<=e){
        ll mid=(s+e)/2;
        if(isValid(arr, n, k, mid)){
            e = mid-1;
            ans = mid;
        }
        else {
            s = mid + 1;
        }
    }

    return ans;
}

int main() {
    ll n,k,t;
    cin>>n>>k>>t;
    ll arr[n];
    
    for(ll i=0; i<n; i++) {
        cin>>arr[i];
    }

    sort(arr,arr+n);
    cout<<(minTime(arr,n,k)%mno * t%mno)%mno;

    return 0;
}