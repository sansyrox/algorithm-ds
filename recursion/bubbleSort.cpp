#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void bubbleSort(int arr[], int i, int n){

    if(i==n-1) return;

    for(int j=0; j<=n-i-1; j++){
        if(arr[j]>arr[j+1]) {
            swap(arr[i],arr[j]);
        }
    }

    bubbleSort(arr,i+1,n);
}

void bubbleSort2(int arr[], int n, int j=0) {
    if(n==1) return;

    if(j==n-1) bubbleSort2(arr,n,0);
    if(j>=n) return;

    if(arr[j]>arr[j+1]) {
        swap(arr[j+1],arr[j]);
    }
    bubbleSort2(arr,n,j+1);
    return;
}

int main() {
    
    int arr[10] = {1,3,2,4,6,5,7,9,8,10};
    bubbleSort2(arr,10,0);
    for(auto i:arr) cout<<i<<" ";
    return 0;
}