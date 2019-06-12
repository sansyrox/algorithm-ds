#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool balancedParanthesis(string s){
    stack<char> x;
    for(auto j:s){
        if(j=='('){
            x.push('(');
        }
        else if(j==')'){
            if(x.size()==0){
                return false;
            }
            else if(x.top()==')'){
                return false;
            }
            else{
                x.pop();
            }
        }
    }

    if(x.size()!=0){
        return false;
    }

    return true;


}

int main() {
    string s;
    cin>>s;
    balancedParanthesis(s)?cout<<"Yes":cout<<"No";
    return 0;
}