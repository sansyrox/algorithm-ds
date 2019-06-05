#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int computeSetBits(int n){
    int ans=0;
    while(n){
        ans++;
        n=n&(n-1);
    }

    return ans;
}


int main() {
    
    return 0;
}