#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

set<string> x;
vector<vector<string> >dp(100001);

void stringGen(string s,int i, int cnt ,int k){
    if(cnt>=k){
        // cout<<s<<endl;
        dp[i][cnt] = s;
        x.insert(s);
        return;
    }

    if(dp[i][cnt]!="z"){
        x.insert(dp[i][cnt]);
        return;
    }
    
    if(i==s.length() and cnt<k){
        // cout<<s<<endl;
        dp[i][cnt] = s;
        x.insert(s);
        return;
    }

    if(s[i]=='a'){
        stringGen(s,i+1,cnt,k);
        s[i]='b';
        stringGen(s,i+1,cnt+1,k);
        // s[i]='a';
    }
    else {
        stringGen(s,i+1,cnt,k);
        s[i]='a';
        stringGen(s,i+1,cnt+1,k);
    }
    



}

int returnMaxLength(){
    int maxL =0;
    int tempmax=0;
    int temp_temp_max=0;
    for(auto i:x){
        int tempmax=0,temp_temp_max=0;
        // cout<<i<<endl;
        for(int j=0; j<i.size()-1;j++){
            
            if(i[j]==i[j+1]){
                temp_temp_max+=1;
                tempmax=max(temp_temp_max,tempmax);
            }
            else {
                temp_temp_max=0;
            }
        }
        maxL = max(maxL,tempmax);
        
    }

    return maxL+1;
}

int main() {
    
    string s;
    int k;

    
    for(int i=0; i<100001;i++){
        vector<string> temp;
        for(int j=0; j<100001; j++){
            temp.pb("z");
        }
        dp.pb(temp);
    }
    // memset(dp,"z",sizeof(dp));
    cin>>s>>k;
    stringGen(s,0,0,k);
    
    cout<<returnMaxLength();

    return 0;
}