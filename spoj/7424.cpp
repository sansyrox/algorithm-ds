#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    double a,b;
    cin>>a>>b;
    while(a!=-1 and b!=-1){
        double mn = min(a,b)+1;
        double mx = max(a,b);
        cout<<ceil(mx/mn)<<endl;


        cin>>a>>b;
    }
    return 0;
}