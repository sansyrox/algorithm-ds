#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    char a[] = "nrfzh";
    int n = sizeof(a)/sizeof(char);

    for(int i=0; i<n-1; i++){
        int x = a[i]-'a';
        x=(x+3)%26;
        a[i] = char(x+'a');
    }

    cout<<a<<endl;

    return 0;
}