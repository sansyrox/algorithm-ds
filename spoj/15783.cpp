#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int maxBipartite(int arr[], int n){
    int lis[n],lds[n];
    for(int i=0; i<n; i++) lis[i] = 1;
    for(int i=0; i<n; i++) lds[i] = 1;

    // increasing
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j] and lis[i]<=lis[j]){
                lis[i] = lis[j] + 1;
            }
        }
    }

    // decreasing
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(arr[i]>arr[j] and lds[i]<=lds[j]){
                lds[i] = lds[j] + 1;
            }
        }
    }

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    // for(int i=0; i<n; i++){
    //     cout<<lis[i]<<" ";
    // }cout<<endl;


    // for(int i=0; i<n; i++){
    //     cout<<lds[i]<<" ";
    // }cout<<endl;

    int ans[n];
    for(int i=0; i<n; i++){
        ans[i] = (lis[i]+lds[i] - 1);
    }

    return *max_element(ans,ans+n);
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<maxBipartite(arr,n)<<endl;
    }
    return 0;
}