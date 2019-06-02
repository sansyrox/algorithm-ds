#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool isValid(int arr[], int n, int k, int ans){
    int count =1; // count of painters
    int sum=0;
    for(int i=0; i<n; i++){
        if(sum+arr[i]>=ans){
            count++;
        }

        if(count>k){
            return false;
        }
        sum+=arr[i];
    }

    return true;

}

int minTime(int arr[], int n, int k) {
    int s=arr[n-1];
    int e=0;
    for(int i=0;i<n; i++){
        e+=arr[i];
    }

    int ans;
    while(s<=e){
        int mid=(s+e)/2;
        if(isValid(arr, n, k, mid)){
            e = mid -1;
            ans = mid;
        }
        else {
            s = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n,k;
    cin>>k>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }

    cout<<minTime(arr,n,k);

    return 0;
}