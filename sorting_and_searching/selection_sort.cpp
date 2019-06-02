#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int arr[10] = {1,2,4,3,5,6,7,8,9,10};
    int n= sizeof(arr)/sizeof(int);    
    for(int i=0; i<n-1; i++){
        int min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        swap(arr[i],arr[min]);
    }

    for(auto i:arr) cout<<i<<" ";

    return 0;
}