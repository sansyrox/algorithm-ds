#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

ll binarySearch(ll arr[], ll s, ll e, int key){

    while(s<=e){
        ll mid= (s+e)/2;

        if(key>arr[mid]){
            s=mid+1;
        }
        else if(key<arr[mid]){
            e = mid-1;
        }
        else{
            return mid;
        }

    }

    return -1;

}

int main() {
    ll n;
    cin>>n;
    ll arr[n];

    for(ll i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;
    cout<<binarySearch(arr, 0,n-1,k);

    return 0;
}