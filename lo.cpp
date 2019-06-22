#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    vector<int> a(10,0);

    for(int i=0 ; i<10; i++) a[i] = 1;

    auto it= unique(a.begin(), a.end());

    a.resize(distance(a.begin(),it));

    for(auto i:a) cout<<i<<" ";
    return 0;
}