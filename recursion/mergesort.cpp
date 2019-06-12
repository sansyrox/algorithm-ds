#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void merge(int arr[],int s,int mid,int e) {
    int i=s,j=mid+1;
    int temp[e+1];
    int k =0;

    while(i<=mid and j<=e){
        if(arr[i]<arr[j]){
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid) {
        temp[k++] = arr[i++];
    }

    while(j<=e) {
        temp[k++] = arr[j++];
    }

    for(int i=s,j=0; i<=e; i++,j++){
        arr[i] = temp[j];
    }


}

void mergeSort(int arr[], int s,int e){
    if(s>=e){
        return ;
    }


    int mid = (s+e)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,mid,e);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    mergeSort(arr,0,n-1);
    for(auto i:arr) cout<<i<<" ";
    return 0;
}