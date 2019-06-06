#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int a,b,c;

    cin>>a>>b>>c;

    int i=(1%c);

    for(int j=0;j<b; j++){
        i*=(a%c);
    }

    cout<<(i%c);

    return 0;
}