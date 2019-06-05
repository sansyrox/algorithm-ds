#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool comparator(string a, string b){
    string max = (a.length()>b.length()) ? a:b;
    string min = (a.length()>b.length()) ? b:a;

    if(max.find(min)==std::string::npos){
        return a<b;
    } else{
        return a.length()>b.length();
    }
}

int main() {
    vector<string> v;
    int n;cin>>n;
    while(n--){
        string t; cin>>t;
        v.pb(t);
        sort(v.begin(),v.end(),comparator);
        
    }    
    for(auto i:v){
            cout<<i<<endl;
        }
    return 0;
}