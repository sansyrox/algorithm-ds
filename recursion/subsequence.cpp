#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
set<string> x;
void printSubs(string s, int i, string a=""){
    if(i==s.length()){
        // cout<<a<<endl;
        x.insert(a);
        return;
    }

    printSubs(s,i+1,a+s[i]);
    printSubs(s,i+1,a);
}

int main() {
    string s="ab";
    int i=0;
    printSubs(s,i);
    for(auto i:x) {
        cout<<i<<endl;
    }
    return 0;
}