#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int posInArray(int arr[], int n, int k, int s, int e) {

    if(e <s){
        return -1;
    }
    int mid = (e+s)/2;
    if(k==arr[mid]){
        return mid;
    }

    // left part sorted
    if(arr[mid]>=arr[s]){
        if(k<=arr[mid] and k>=arr[s]){
            return posInArray(arr,n,k,s,mid-1);
        } else {
            return posInArray(arr,n,k,mid+1,e);
        }

    }
    // right part sorted
    if(k>=arr[mid] and k<=arr[e]){
        return posInArray(arr,n,k,mid+1,e);
    }else {
        return posInArray(arr,n,k,s,mid-1);
    }

}

int main() {
    int arr[10] = {7,8,9,10,1,2,3,4,5,6};
    int k = -1;
    int n=10;
    cout<<posInArray(arr, n, k,0,10);
    return 0;
}