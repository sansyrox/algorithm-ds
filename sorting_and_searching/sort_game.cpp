#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool myComparator(pair<string,int> a, pair<string,int> b) {
    if(a.second!=b.second){
        return a.second > b.second;
    }
    return a.first < b.first;
}

int main() {
    int x;
    cin>>x;
    int n;
    cin>>n;
    vector<pair<string, int> >v;
    while(n--){
        string s;
        int sal;
        cin>>s>>sal;
        v.pb(mp(s,sal));
    }

    sort(v.begin(),v.end(),myComparator);

    for(auto i:v){
        if(i.second >= x) cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}