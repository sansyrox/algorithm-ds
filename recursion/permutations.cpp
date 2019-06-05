#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void permutations(string &s, int i=0){
    if(i==s.length()){
        cout<<s<<endl;
        return;
    }

    
    for(int j=i; j<s.length(); j++){
        swap(s[i], s[j]);
        permutations(s,i+1);
        swap(s[i], s[j]);
    }

}


int main() {
    
    string s = "abc";
    permutations(s,0);

    return 0;
}