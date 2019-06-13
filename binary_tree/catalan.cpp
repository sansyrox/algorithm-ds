#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int dp[1000] = {0};

int catalan(int n){

    if(n<0) return 0;
    if(n==0){
        return 1;
    }

    if(dp[n]!=0) {
        return dp[n];
    }

    int sum=0;
    for(int i=1;i<n; i++){
        sum+= catalan(i-1)*catalan(n-1);
    }

    return dp[n] = sum;


}

int main() {
    
    return 0;
}