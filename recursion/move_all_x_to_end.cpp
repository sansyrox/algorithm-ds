#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ll long long
#define pb push_back

string moveXatTheEnd(string s, int i,int cnt, string o){

    // cout<<"Line 9"<<endl;
    if(i==s.length()){
        // cout<<cnt<<endl;
        while (cnt--){
            o+="x";
        }
        return o;
    }

    if(s[i]=='x'){
        return moveXatTheEnd(s,i+1,cnt+1,o);
    }

    o.push_back(s[i]);
    // cout<<"Line 25"<<endl;
    return moveXatTheEnd(s,i+1,cnt, o);

}

int main(){
    string s;
    cin>>s;

    cout<<moveXatTheEnd(s,0,0,"");

    return 0;
}