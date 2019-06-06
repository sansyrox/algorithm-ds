#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int isValid(int arr[], int n, int m, int ans){

    ll s=0;
    ll cnt=1;
    // int temp_max=0;
    for(int i=0; i<n; i++){
        
        if(s+arr[i]>ans){
            s=arr[i];
            cnt++;
        }else {
            s+=arr[i];
        // temp_max+=arr[i];
        }
        
    }

    // if(ans==117){
    //     cout<<cnt<<endl<<m<<endl;
    // }
    // cout<<final_max<<endl;
    return (cnt<=m)?1:0;

}

int bookAllocation(int arr[], int n, int m){
    int s = arr[n-1];
    int e =0;
    for(int i=0; i<n; i++){
        e+=arr[i];
    }
    int ans=0;
    while(s<=e){
        int mid = (s+e)/2;
        // cout<<"Mid is "<<mid<<endl;
        if(isValid(arr,n,m,mid)){
            ans=mid;
            e = mid-1;
            
        }
        else {
            s=mid+1;
        }


    }

    return ans;
}

int main() {

    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<bookAllocation(arr,n,m)<<endl;
    }
    
    return 0;
}