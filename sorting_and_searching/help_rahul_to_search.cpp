#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int returnIndex(int arr[],int k, int s, int e) {
    if(s>e){
        return -1;
    }

    int mid = (s+e)/2;

    if(arr[mid]==k){
        return mid;
    }

    // if left is sorted
    if(arr[s]<arr[mid]){
        if(k>=arr[s] and k<arr[mid]){
            return returnIndex(arr,k,s,mid-1);
        }
        else {
            return returnIndex(arr,k,mid+1,e);
        }
    }
    // if right is sorted
    if(k>arr[mid] and k<=arr[e]){
        return returnIndex(arr,k,mid+1,e);
    }
    return returnIndex(arr,k,s,mid-1);

}

int main() {
    int n;cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;
    cout<<returnIndex(arr,k,0,n-1);

    return 0;
}