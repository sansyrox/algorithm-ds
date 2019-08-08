#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

#define max_n 1000007

ll arr[1000001]={0};






int main() {
    arr[1]=2;
    for(ll i=2; i<1000001; i++){
        arr[i] = ((arr[i-1]%max_n) + (2*i + (i-1)%max_n) )%max_n;
    }
    
    int t; cin>>t;

    while(t--){
        ll n; cin>>n;
        // if(n==0) {cout<<0;continue;}
        // if(n==1) {cout<<2;continue;}

        // ll arr[n+1];
        // fill(arr,arr+(n+1),0);
        // arr[0]=0,arr[1]=2;

        // for(ll i=2; i<=n; i++){
        //     arr[i] = ((arr[i-1]%max_n) + (2*i + (i-1)%max_n) )%max_n;
        // }

        cout<<arr[n]<<endl;
    }
    return 0;
}