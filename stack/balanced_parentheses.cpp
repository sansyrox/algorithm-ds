#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    string s;
    cin>>s;
    stack<char> x;

    bool balanced = true;
    for(auto j:s){
        if(j=='{' or j=='(' or j=='['){
            x.push(j);
        }

        if(j=='}'){
            if(x.top()!='{') {
                balanced = false;
                break;
            }
            x.pop();
        }

        if(j==')'){
            if(x.top()!='(') {
                balanced = false;
                break;
            }
            x.pop();
        }
        
        if(j==']'){
            if(x.top()!='[') {
                balanced = false;
                break;
            }
            x.pop();
        }

    }

    if(!balanced or !x.empty()){
        cout<<"No";
    }
    else {
        cout<<"Yes";
    }


    return 0;
}