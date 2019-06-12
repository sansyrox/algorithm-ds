#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int noOfSteps(string s, int d){
    string cpy(s);
    double cnt=0;
    for(auto j:s) if(j=='P') cnt+=1;

    double percent=((cnt)/d);

    if(percent>=0.75)
        return 0;
    
    // add a check for i==1
    int steps=0;
    for(int i=2; i<=d-3; i++){
        percent=((cnt)/d);

        if(percent>=0.75)
            return steps;

        if(cpy[i]=='A' and (s[i-1]=='P' or s[i-2]=='P') and (s[i+1]=='P' or s[i+2]=='P')){
            cpy[i]='P';
            cnt+=1;
            steps++;
        }
    }

    // i>=n-2
    return (percent>=75.0)?steps:-1;

}

int main() {

    int t; cin>>t;
    int d;
    string s;
    while(t--){
        cin>>d;
        cin>>s;
        cout<<noOfSteps(s,d)<<endl;
    }

    return 0;
}