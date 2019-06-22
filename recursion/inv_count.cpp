#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back



// void mergeSort(int arr[], int s, int e){
//     if(s>e){
//         return;
//     }

//     int mid = (s+e)/2;

//     mergeSort(arr,s,mid);
//     mergeSort(arr,mid+1,e);
//     merge(arr,s,e);
// }

int i=0;

bool comp(pair<int,int> a, pair<int,int> b){
    if(a.first>b.first and a.second>b.second ){
        i++;
        // cout<<a<<" "<<b<<endl;
    }

    return a.first<b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin>>t;
    vector<int> a;
    while(t--){
        i=0;
        int n; cin>>n;
        for(int i=0; i<n; i++) {
            int t; cin>>t;
            a.pb(t);
        }
        vector<pair<int,int> >v;
        for(int i=0; i<n; i++){
            v.pb(mp(a[i],i));
        }
        // mergesort()
        sort(v.begin(), v.end(),comp);
        cout<<i<<endl;
        a.clear();
    }
    return 0;
}