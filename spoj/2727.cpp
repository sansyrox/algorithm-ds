#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int t; cin>>t;
    while(t--){
        // char s; cin>>s;
        int n,m; cin>>n>>m;
        vector<int> ng,nm;

        for(int i=0; i<n; i++){
            int t; cin>>t;
            ng.pb(t);
        }

        for(int i=0; i<m; i++){
            int t; cin>>t;
            nm.pb(t);
        }

        sort(ng.begin(),ng.end());
        sort(nm.begin(),nm.end());

        while(!ng.empty() and !nm.empty()){
            ng.back()<nm.back() ? ng.pop_back(): nm.pop_back();
        }

        if(nm.empty()){
            cout<<"Godzilla\n";
        }
        else {
            cout<<"MechaGodzilla\n";
        }

    }
    return 0;
}