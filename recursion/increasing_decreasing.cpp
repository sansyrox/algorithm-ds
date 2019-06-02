#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void printNumbers(int n){
    cout<<n<<endl;
    if(n==1){
        return;     
    }

    
    return printNumbers(n-1);
}

int main() {
    int n;
    cin>>n;
    printNumbers(n);
    return 0;
}