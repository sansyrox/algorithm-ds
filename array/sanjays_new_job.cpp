#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<string, int > p1, pair<string , int> p2){
    if(p1.second != p2.second){
        return p1.second < p2.second;
    }
    else {
        return p1.first < p2.first
    }
}

int main() {
    int x,n;
    cin>>x>>n;
    vector<pair<string, int> > v;
    while(n--) {
        
        string s; int a;
        cin>>s>>a;
        v.push_back(make_pair(s,a));
    }

    sort(v.begin(),v.end(), comparator);

    for(auto i:v) {
        cout<<i.first<<" "<<i.second<<endl;
    }

    return 0;
}