#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


ll merge(ll arr[], ll s, ll mid, ll e) {
    ll mergeA[s+e+1];
    ll count=0;
    ll i=s,j=mid+1,k=0;
    // exit(0);
    while(i<=mid and j<=e){
        if(arr[i]<arr[j])
            mergeA[k++] = arr[i++];
        else {
            mergeA[k++] = arr[j++];
            count+= mid - i + 1;
        }
            
    }

    while(i<=mid){
        mergeA[k++]=arr[i++];
    }

    while(j<=e){
        mergeA[k++]=arr[j++];
    }

    for(ll x=s; x<=e; x++){
        arr[x] = mergeA[x-s];
    }

    return count;
}

ll mergeSort(ll arr[], ll s, ll e){
    if(s>=e){
        return 0;
    }

    ll mid = s + (e-s)/2;

    ll x = mergeSort(arr,s,mid);
    ll y = mergeSort(arr,mid+1,e);
    ll z = merge(arr,s,mid,e);

    return x+y+z;


}

int main() {
    ll t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll arr[n];
        for(ll i=0; i<n; i++) cin>>arr[i];

        cout<<mergeSort(arr,0,n-1)<<endl;

    }
    return 0;
}