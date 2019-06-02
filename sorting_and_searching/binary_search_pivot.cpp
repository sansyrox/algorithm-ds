#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int returnPivotElement(int a[], int n){
    int s=0,e=n-1;

    while(s<=e){
        int mid=(s+e)/2;
        // cout<<mid<<endl;
        if(a[mid]<a[mid-1]) {
            return mid-1;
        }
        else if(a[mid]>a[mid+1]) {
            return mid;
        }
        else {
            if(a[mid]>a[e]) {
                s=mid+1;
            }
            else {
                e = mid-1;
            }
        }
        
    }

    return -1;

}

int main() {
    int n;cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<returnPivotElement(arr,n);
    return 0;
}