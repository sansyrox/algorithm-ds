#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    float x; cin>>x;
    while(x){
        float sum=0;
        float i;
        for(i=1; sum<=5.20 and sum<x;i++){

            sum+=(1/(i+1));
            
        }
        cout<<i<<" card(s)\n";
        cin>>x;
    }
    return 0;
}