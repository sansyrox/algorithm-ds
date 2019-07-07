#include <iostream>
#include<list>
using namespace std;

int dp[21];
class Node{
    
}

int ans(string s, int i=0){
    // if(i==s.length()-1){
    //     return s[i]-'0';
    // }
    if(i==s.length()){
        return 0;
    }
    
    // if(dp[i]!=-1){
    //     return dp[i];
    // }

    int x = s[i]-'0';
    int ans1 = ans(s,i+1);
    if(x==0){
        return ans1;
    }
    cout<<ans1<<endl;
    return dp[i]=max(x*ans1,x+ans1);    
    
}

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    string s; cin>>s;
	    sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        
        memset(dp,-1,sizeof(dp));
	    cout<<ans(s,0)<<endl;
	    
	}
	return 0;
}