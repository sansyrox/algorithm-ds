#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int t; cin>>t;
    while(t--){
        ll a,b,c;
        cin>>a>>c>>b;
        ll n = ((2*b)/(a+c));
        ll d = (c-a)/(n-5);
        cout<<n<<endl;
        ll A = a - 2*d;
        for(int i=1; i<=n; i++){
            cout<<A<<" ";
            A+=d;
        }
        cout<<endl;
    }
    return 0;
}