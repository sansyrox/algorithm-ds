#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back




bool canSplit(string s,vector<unordered_map<string,bool> > &dp, unordered_map<string, bool> &dict, string o="", int i=0){
    if(i==s.length() and o==""){
        return true;
    }

    if(i==s.length()){
        return false;
    }

    if(dp[i].count(o)!=0)
        return dp[i][o];

    o.pb(s[i]);
    if(dict[o]==true){
        o.clear();
    }

    return dp[i][o] = canSplit(s,dp,dict,o,i+1);

}

int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        unordered_map<string,bool> dict;
        for(int i=0; i<n; i++){
            string s; cin>>s;
            dict[s] = true;
        }
        string s; cin>>s;
        // unordered_map<string,dp
        // dp.clear();
        // dp(1001);
        vector<unordered_map<string,bool> > dp(1001);
        canSplit(s,dp,dict,"") ? cout<<"1\n":cout<<"0\n";
    }
    return 0;
}


// bool func(string &s,int i, vector<int>&dp){
    
//     if(i==s.length())
//     return 1;
//     if(dp[i]!=-1)
//     return dp[i];
//     for(int j=i+1;j<=s.length();++j){
//         if(dict.find(s.substr(i,j-i))!=dict.end()){
            
//             if(func(s,j,dp)){
//                 return dp[i]=1;
//             }
//         }
//     }
//     return dp[i]=0;
    
// }
// int main() {
// 	int t;
// 	cin>>t;
// 	while(t--){
// 	    int n;
// 	    string a,s;
// 	    cin>>n;
// 	    dict.clear();
// 	    while(n--){
// 	        cin>>a;
// 	        dict.insert(a);
// 	    }
// 	    cin>>s;
// 	    vector<int>dp(s.length(),-1);
// 	    cout<<func(s,0,dp)<<endl;<br>
// 	}

// 	return 0;

// }