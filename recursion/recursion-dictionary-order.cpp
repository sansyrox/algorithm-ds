#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#include<unordered_set>

set<string> helper; 

void generatePermutations(string &s, int i){
    if(i==s.length()){
        helper.insert(s);
        return;
    }

    for(int j=i; j<s.length(); j++){
        swap(s[i],s[j]);
        generatePermutations(s,i+1);
        swap(s[i],s[j]);
    }
}

int main() {
    string s;
    cin>>s;
    string cpy(s);
    
    generatePermutations(s,0);

    bool print=true;

    for(auto i:helper){
        if(i<cpy) {
            cout<<i<<endl;
        }
        
    }

    return 0;
}