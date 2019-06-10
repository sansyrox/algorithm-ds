#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
#define pb push_back

string replaceAllPi(string s, int i, string o){

    if(i==s.length()){
        return o;
    }

    if(i==s.length()-1){
        return o+s[i];
    }

    if(s[i]=='p' and s[i+1]=='i'){
        o+="3.14";
        i+=2;
        return replaceAllPi(s,i,o);
    }

    o+=s[i];
    i++;
    return replaceAllPi(s,i,o);


}

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        cout<<replaceAllPi(s,0,"")<<endl;
    }
    return 0;
}