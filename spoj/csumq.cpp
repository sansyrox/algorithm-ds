#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    int q; cin>>q;
    int sum[n];
    sum[0] = arr[0];

    for(int i=1; i<n; i++){
        sum[i] = arr[i] + sum[i-1];
    }

    while(q--){
        int a,b;
        cin>>a>>b;
        if(a==b) {
            cout<<arr[a]<<endl;
            continue;
        }

        if(a!=0){
            cout<<sum[b]-sum[a-1]<<endl;
        }
        else {
            cout<<sum[b]<<endl;
        }
    }

    return 0;
}