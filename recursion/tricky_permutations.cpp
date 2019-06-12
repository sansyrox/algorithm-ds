#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

vector<string> v;

bool find(vector<string> v, string s){
    for(auto j:v){
        if(j==s) return true;
    }

    return false;
}

void genPerms(string a, int i=0){
    if(i==a.length()){
        // cout<<a<<endl;
        if( !find(v,a)){
            v.pb(a);
        }
        
        return;
    }

    for(int j=i; j<a.length(); j++){
        swap(a[i],a[j]);
        genPerms(a,i+1);
        // swap(a[i],a[j]);
    }

}

int main() {
    string a; cin>>a;
    sort(a.begin(), a.end());
    genPerms(a,0);

    for(auto j:v) cout<<j<<endl;
    return 0;
}