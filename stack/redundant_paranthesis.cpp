#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool isRedundant(string a){
    stack<char> s;

    for(auto j:a){
        if(j=='(' or j=='+' or j=='*' or j=='-' or j=='/' or (j>='a' and j<='z') or (j>='A' and j<='Z')){
            s.push(j);
        }

        else if(j==')'){
            if(s.top()=='('){
                return true;
            }

            while(s.top()!='('){
                s.pop();
            }
            s.pop();
        }
    }

    if(s.size()==0) return false;

    return true;

}

int main() {
    int t;
    cin>>t;
    while(t--){
        string a; cin>>a;
        isRedundant(a)==true?cout<<"Duplicate\n":cout<<"Not Duplicates\n";
    }
    

    return 0;
}