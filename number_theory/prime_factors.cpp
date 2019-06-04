#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int primeFactors(int a, int b){
    if(b==0){
        return a;
    }

    return primeFactors(b, a%b);
}

int main() {
    int a,b;
    cin>>a>>b;
    cout<<primeFactors(a,a)<<endl;
    return 0;
}