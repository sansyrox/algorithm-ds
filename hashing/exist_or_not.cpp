#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#include<unordered_map>

int main() {
    int t; cin>>t;
    map<int,bool> u;
    while(t--){
    
    
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
        u[arr[i]] = true;
    }
    int q; cin>>q;
    while(q--){
        int a; cin>>a;
        if(u[a]) cout<<"Yes\n";
        else cout<<"No\n";
    }
    u.clear();
    }
    return 0;
}