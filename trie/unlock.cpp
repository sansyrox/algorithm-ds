#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void permutation(string &s, int i,int k, priority_queue<string> &pq){
    if(k==1){
        pq.push(s);
        return;
    }

    if(i==s.length()){
        pq.push(s);
        return;
    }

    for(int j=i; j<s.length(); j++){
        swap(s[i],s[j]);
        permutation(s,i+1,k-1,pq);
        swap(s[i],s[j]);
        k++;
    }
    return;
}

int main() {
    
    int n;cin>>n;
    int k; cin>>k;

    string s="";
    for(int i=0; i<n; i++){
        string t; cin>>t;
        s+=t;
    }
    // cout<<s;
    priority_queue<string> pq;
    // cout<<"Idhar";
    permutation(s, 0,k, pq);
    string sp = (!pq.empty()) ? pq.top():"";

    for(auto j:sp) cout<<j<<" ";
    return 0;
}