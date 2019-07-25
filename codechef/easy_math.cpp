#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool comp(string a, string b){
    int x=0,y=0;

    for(auto i:a) x+= (int)(i-'0');
    for(auto i:b) y+= (int)(i-'0');

    return x>y;
}

int ans(int arr[], int n){
    vector<string> an;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++){
            an.push_back(to_string(arr[i]*arr[j]));
        }
    }

    sort(an.begin(),an.end(),comp);
    return stoi(an[0]);
}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        int x = ans(arr,n);
        int y=0;
        while(x){
            y+=(x%10);
            x/=10;
        }
        cout<<y<<endl;
    }
    return 0;
}