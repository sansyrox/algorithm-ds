#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// lastIndex = s.size()-1
int rhash(string s, int lastIndex){
    int sum =0;
    for(int i=0; i<=lastIndex; i++) {
        sum+= int(s[i]-'0');
    }

    return sum;
}

bool rabinKarp(string s, string k) {
    int kHash = rhash(k, k.length()-1);
    int sInitHash = rhash(s, k.length()-1);

    // cout<<"line 1\n";

    for(int i=k.length()-1; i <=s.length(); i++){
        // cout<<"line 1\n";
        if(i!=k.length()-1){
            sInitHash += (int)(s[i]);
        }

 
        if(kHash==sInitHash) {
            // cout<<"Idahr\n";
            if(k==s.substr(i-(k.length()-1), k.length())){
                // cout<<"Idahr\n";
                return true;
            }
        }


        sInitHash -= (int)(s[i]);
    }

    return false;
}


int main() {
   string s,k;
    cin>>s>>k;

    cout<<rabinKarp(s,k);
   return 0;
}