#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int a;
    cin>>a;
    int ans=0;
    while(a>0){
        ans+=(a&1);
        a=a>>1;

    }

    cout<<ans<<endl;

    return 0;
}