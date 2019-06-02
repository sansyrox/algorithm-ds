#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int binarySearchUpperBound(int arr[], int n, int key){
    int s=0,e=n-1;
    int ans = -1;

    while(s<=e){
        int mid=(s+e)/2;
        
        if(arr[mid]<key){
            s=mid+1;
        }
        else if (arr[mid]>key) {
            e = mid -1;
        }
        else {
            ans = mid;
            s = mid + 1;
        }
    }

    return ans;
}

int binarySearchLowerBound(int arr[], int n, int key){
    int s=0,e=n-1;
    int ans = -1;

    while(s<=e){
        int mid=(s+e)/2;
        
        if(arr[mid]<key){
            s=mid+1;
        }
        else if (arr[mid]>key) {
            e = mid -1;
        }
        else {
            ans = mid;
            e = mid -1;
        }
    }

    return ans;
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ;i++){
        cin>>arr[i];
    }
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<binarySearchLowerBound(arr,n,x)<<" "<<binarySearchUpperBound(arr,n,x)<<endl;
    }
    return 0;
}