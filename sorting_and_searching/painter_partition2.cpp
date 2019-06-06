#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define maxima 10000003

bool isPossible(ll arr[], ll n, ll k, ll ans){
    ll cnt=1;

    ll sum=0;
    for(ll i=0; i<n; i++){
        if(sum+arr[i]>ans){
            sum = arr[i];
            cnt++;
        }else {
            sum+=arr[i];
        }
    }

    return cnt>k?0:1;

}

ll binarySearchPainter(ll arr[], ll n, ll k){
    ll s=arr[n-1];
    ll e=0;
    for(ll i=0; i<n; i++) e+=arr[i];

    int ans=0;
    while(s<=e){
        ll mid = (s+e)/2;
        if(isPossible(arr,n,k,mid)){
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
    // cout<<n<<k<<t;
    ll arr[n];
    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<(ll)(((binarySearchPainter(arr,n,k)%maxima)*(t%maxima))%maxima);

    return 0;
}