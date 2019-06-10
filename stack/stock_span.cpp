#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void printSpan(int arr[], int n){
    int span[n];
    stack<int> helper; // storing the index;
    span[0] = 0; 

    helper.push(0);

    for(int i=1;i<n; i++){
        while(arr[i]>arr[helper.top()] and !helper.empty()) {
            helper.pop();
        }
        span[i] = i - helper.top();
        helper.push(i);
    }
    span[0] = 1;


    for(int i=0; i<n; i++){
        cout<<span[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        printSpan(arr, n);

    }
    return 0;
}