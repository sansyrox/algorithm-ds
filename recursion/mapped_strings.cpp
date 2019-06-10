// We are given a hashmap which maps all the letters with number. Given 1 is mapped with A, 2 is mapped with B…..26 is mapped with Z. Given a number, you have to print all the possible strings.

// Input Format:
// A single line contains a number.


#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
#define pb push_back

void printAllStrings(map<int, char> m,string s, int i, string o){
    if(i==s.length()){
        cout<<o<<endl;
        return;
    }

    if(i==s.length()-1){
        o.push_back(m[s[i]-'0']);
        // cout<<"O is"<<m[s[i]-'0']<<endl;
        cout<<o<<endl;
        return;
    }

    string cp(o);
    cp.push_back(m[s[i]-'0']);
    printAllStrings(m,s,i+1,cp);

    string x=s.substr(i,2);
    // cout<<x<<endl;
    

    if(stoi(x)<=26 and stoi(x)>=1){
        int y = stoi(x);
        // cout<<m[y];
        o.push_back(m[y]);
        // cout<<"O is "<<o<<endl;;
        i+=2;
        printAllStrings(m, s,i,o);
    }
    return;


}


int main(){
    map<int, char> m;
    for(int i=1;i<=26; i++){
        m[i] = char('A'+i-1);
    }

    string s;
    cin>>s;
    printAllStrings(m,s,0,"");


    return 0;
}