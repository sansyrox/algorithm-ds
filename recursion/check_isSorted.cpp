#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int checkSorted(int *arr, int n, int i){
    if(i==n-1){
        return 1;
    }

    if(arr[i]>arr[i+1]){
        return -1;
    }

    return checkSorted(arr, n, i+1);
}

int main() {
    int arr[10] = {1,2,3,4,5,0,7,8,9,10};

    cout<<checkSorted(arr,10,0);

    return 0;
}