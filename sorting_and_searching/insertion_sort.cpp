#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int arr[10] = {2,1,3,4,5,6,7,8,9,10};

    int n= sizeof(arr)/sizeof(int);

    for(int i=1; i<n-1; i++){
        int no = arr[i];
        int j=i-1;

        while(j>=0 and arr[j]>no){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = no;
    }

    for(auto i:arr) cout<<i<<" ";
    return 0;
}