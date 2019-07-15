#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int catalan(int n){
    if(n<=1){
        return 1;
    }

    int sum=0;
    for(int i=0; i<n; i++){
        sum+=catalan(i)*catalan(n-i-1);
    }

    return sum;
}


int main() {
    int n; cin>>n;
    cout<<catalan(n)<<endl;
    return 0;
}