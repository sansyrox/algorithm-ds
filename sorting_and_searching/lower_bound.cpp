#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int bSearchLowerBound(int arr[], int n, int key) {
    int s=0, e=n-1;
    int ans = -1;

    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key) {
            ans = mid;
            e = mid-1;
        }
        else if(arr[mid]>key){
            e = mid-1;
        } else {
            s = mid+1;
        }
    }

    return ans;
}

int main() {
    int arr[10] = {1,2,2,2,4,5,6,7,8};
    cout<<bSearchLowerBound(arr, sizeof(arr)/sizeof(int), 10);
    return 0;
}