#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#include<unordered_set>

set<vector<int> > u;

void checkSum(int t){

    for(auto i:u){
        int sum =0;
        for(auto j:i){
            sum+=j;
        }

        if(sum==t){
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
    }

}

void subsetGen(int arr[],vector<int> o,int n, int i=0){

    if(i==n){
        sort(o.begin(),o.end());
        u.insert(o);
        return;
    }

    subsetGen(arr,o,n,i+1);
    o.pb(arr[i]);
    subsetGen(arr,o,n,i+1);
    return;
}

int main() {
    int n,t;
    cin>>n;
    int arr[n];
    vector<int> o;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>t;

    subsetGen(arr,o,n,0);
    checkSum(t);



    return 0;
}