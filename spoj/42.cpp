#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int t; cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        ll x,y;
        x = stoll(a);
        y = stoll(b);
        x+=y;
        string z = to_string(x);
        reverse(z.begin(),z.end());
        x = stoll(z);
        cout<<x<<endl;

    }
    return 0;
}