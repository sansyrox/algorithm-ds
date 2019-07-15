#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

string ans(string s){
    stack<char> x;
    string o="";
    for(auto i:s){
        if(i>='a' and i<='z'){
            o.pb(i);
        }
        else if(i=='(' || i=='+'||i=='*'||i=='^'||i=='-'||i=='/'){
            x.push(i);
        }
        else if(i==')'){
            while(!x.empty() and x.top()!='('){
                o.pb(x.top());
                x.pop();
            }
            if(!x.empty() and x.top()=='('){
                x.pop();
            }
        }
    }

    return o;
}

int main() {
    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        string y = ans(s);
        cout<<y<<endl;
    }
    return 0;
}