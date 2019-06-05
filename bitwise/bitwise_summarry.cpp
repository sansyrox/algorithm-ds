#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int getIthBit(int n, int i){
    return (n & (1<<i)) != 0?1:0;
}

void setIthBit(int &n, int i){
    int mask = 1<<i;
    n = n|mask;
}

int main() {
    
    return 0;
}