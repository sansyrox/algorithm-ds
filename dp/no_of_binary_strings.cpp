// COUNT NUMBER OF BINARY STRINGS
// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.
//

#include<iostream>
#include<vector>

const long long me = 10e9 + 7;

using namespace std;

long long dp[105]; 

void returnCount(){
    for (int i = 2; i <=104; i++) { 
        dp[i] = (dp[i-1]%1000000007 + dp[i-2]%1000000007)%1000000007;
    }
}


int main() {
    int t; cin>>t;
    dp[0]=dp[1]=1;
    returnCount();
    while(t--){
        int n; cin>>n;
        cout<<(dp[n+1])<<endl;
    }
	return 0;
}