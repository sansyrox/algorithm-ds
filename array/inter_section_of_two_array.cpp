#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int n; cin>>n;
    int a2[n];
    unordered_map<int,int> um;
    for(int i=0; i<n; i++) {
        int t; cin>>t;
        if(!um[t]){
            um[t]=1;
        }else {
            um[t]+=1;
        }
    }

    // cout<<endl<<endl;
    // for(auto j:um) cout<<j.first<<" "<<j.second<<endl;

    for(int i=0; i<n; i++) cin>>a2[i];

    vector<int> a;
    // cout<<endl<<endl;
    for(auto i:a2){
        if(um[i] and um[i]>0){
            a.pb(i);
            um[i]-=1;
        }
    }

    sort(a.begin(),a.end());
    cout<<"[";
    for(int i=0; i<a.size()-1; i++){
        cout<<a[i]<<", ";
    }
    cout<<a[a.size()-1]<<"]";

    return 0;
}