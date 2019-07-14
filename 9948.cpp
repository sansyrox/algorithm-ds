#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    ll n; cin>>n;
    if((n&(n-1))==0||n<=1){
        cout<<"TAK\n";
    }
    else {
        cout<<"NIE\n";
    }
    return 0;
}