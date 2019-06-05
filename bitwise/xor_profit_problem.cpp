#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int maxSetBit(int n){
    int i=0;
    while(n){
        i++;
        n=n>>1;
    }

    return i;
}

int maxXor(int x, int y){
    int xor_sum = x^y;
    int maxIndex = maxSetBit(xor_sum);
    // cout<<"Max index"<<maxIndex<<endl;
    return ((1<<maxIndex) - 1);
}

int main() {
    int x,y;
    cin>>x>>y;
    cout<<maxXor(x,y);   
    return 0;
}