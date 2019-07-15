#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int returnCount(int n){
    // int ans = 1;
    int count = 0;

    for(int i=5; n/i>=1; i*=5){
        count+= n/i;
    }

    return count;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<returnCount(n)<<endl;
    }
    return 0;
}