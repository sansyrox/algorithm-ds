#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#include<unordered_map>

unordered_map<ll,ll> dp;
ll ans12(string s, ll i){
    if(i==s.length()||(i==s.length()-1 and s[i]!='0')){
        return 1;
    }

    if(dp[i]) return dp[i];

    if(s[i]=='0'){
        return dp[i]=0;
    }


    ll ans=0;

    if(s[i]>='1' and s[i]<='9'){
        ans+=ans12(s,i+1);
    }

    if(s[i]=='1' and s[i+1]>='0' and s[i+1]<='9'){
        ans+=ans12(s,i+2);
    }
    
    if(s[i]=='2' and s[i+1]>='0' and s[i+1]<='6'){
        ans+=ans12(s,i+2);
    }

    // and s[i]<='2' 

    return dp[i]=ans;
}

int main() {
    string s; cin>>s;
    while(s!="0"){
        dp.clear();
        cout<<ans12(s,0)<<endl;
        cin>>s;
    }
    return 0;
}