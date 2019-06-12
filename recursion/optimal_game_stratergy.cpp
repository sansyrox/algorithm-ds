#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int maxValue(int arr[], int i, int j){
    if(i>j){
        return 0;
    }

    return max(
        arr[i] + min(
            maxValue(arr,i+2,j),
            maxValue(arr,i+1,j-1)
        ),
        arr[j] + min(
            maxValue(arr,i+1,j-1),
            maxValue(arr,i,j-2)
        )
    );
}

int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<maxValue(arr,0,n-1);
    return 0;
}