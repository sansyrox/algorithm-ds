#include<bits/stdc++.h>
#include<vector>
#define ll long long int
using namespace std;

vector<int> KS2(ll n){
	int digitSum = 0;
	vector<int> ans;
	while(n>0){
		digitSum += n%10;
		ans.push_back(n%10);
		n = n/10;
	}
	int required = digitSum%10;
	reverse(ans.begin(),ans.end());
	ans.push_back(required);
	return ans;
}
int main(){
	int t;
	cin>>t;
    ll n;
	for(int i=0;i<t;i++){
		cin>>n;
		vector<int> ans=KS2(n);
		for(auto j:ans) cout<<j;
		cout<<endl;
	}
}