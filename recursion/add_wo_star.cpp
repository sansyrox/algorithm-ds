// Multiply two numbers without using *

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int multiply(int a, int b){
    if(b==0){
        return 0;
    }

    if(b>0){
        return a + multiply(a,b-1);
    }
    else {
        return -a + multiply(a,b+1);
    }
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<multiply(a,b);
    return 0;
}