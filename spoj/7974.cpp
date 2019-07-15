#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    long double a,b,c;
    cin>>a>>b>>c;

    while(a || b || c){
        // cout<<a<<b<<c<<endl;
        if(c-b==b-a and (c-b!=0)){
            cout<<"AP "<<c+(c-b)<<endl;
        }
        else {
            if(b!=0)
            cout<<"GP "<<c*(c/b)<<endl;
        }
        cin>>a>>b>>c;
    }
    return 0;
}