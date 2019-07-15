#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int ans(int a, int b){

    int ams=1;
    while(b>=1){
        if(b&1){
            ams =((ams%10)*(a%10))%10;
            // b--;
        }
        // else {
            a=((a%10)*(a%10))%10;
            b=b>>1;
        // }

        // ams=((ams%10)*(a%10))%10;1

    }

    return ams;
}

int main() {
    int t; cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        cout<<ans(a,b)<<endl;
    }
    return 0;
}