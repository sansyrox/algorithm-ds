#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int powerAB(int a, int b){

    if(b==1){
        return a;
    }
    int x;
    if(b%2==0){
         x = powerAB(a,b/2);
         x*=x;
    } else {
        x = powerAB(a,b/2);
        x*=x;
        x*=a;
    }
    

    return x;
    
}

int main() {
    cout<<(powerAB(-1,1)%20);
    return 0;
}