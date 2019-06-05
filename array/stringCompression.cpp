#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

string outputString(string s){
    string x="";
    if(s.length()==1){
        x+=s[0]+to_string(1);
        return x;
    }

    int i=0; 

    while(i<s.length()){
        int j=0;
        char y = s[i];
        while(s[i]==s[i+1]){
            j++;
            i++;
        }
        x+=y + to_string(j+1);
        i++;
    }

    return x;

}

int main() {
    string s;
    cin>>s;


    string c = outputString(s);
    cout<<c;


    return 0;
}