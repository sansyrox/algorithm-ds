#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int binarySearch(int arr[], int s, int e, int n, int key){
    if(s>e){
        return -1;
    }

    int mid = (s+e)/2;

    if(arr[mid]==key){
        return mid;
    }

    if(arr[mid]<key){
        return binarySearch(arr,s+1,e,n,key);
    }

    return binarySearch(arr,s,e-1,n,key);

}

int main() {
    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    cout<<binarySearch(arr,0,9,10,7)<<endl;
    return 0;
}