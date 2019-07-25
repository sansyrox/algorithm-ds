#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    string s;
    // int n; cin>>n;
    cin>>s;
    int n; cin>>n;
    while(n--){
        int a,k;
        cin>>a;
        if(a==1) {
            cin>>k;
            for(int i=0; i<s.length(); i++){
                // cout<<(int)s[i]-'a' <<endl;
                int x = (int)s[i]-'a';
                x = (x+k)%26;
                // cout<<char(x+'a')<<endl;
                s[i] = char(x+'a');
            }
        }
        else {
            cin>>k;
            for(int i=0; i<k; i++) cout<<s[i];
            cout<<endl;
        }
    }
    
    

    // cout<<s;
    return 0;
}