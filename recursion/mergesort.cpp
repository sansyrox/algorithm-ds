#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void merge(int arr[],int s,int mid,int e) {
    int i=s,j=mid+1;
    int temp[100];
    int k =s;

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

    for(int i=s; i<=e; i++){
        arr[i] = temp[i];
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
    int arr[5]={1,3,2,4,5};
    mergeSort(arr,0,4);
    for(auto i:arr) cout<<i<<" ";
    return 0;
}