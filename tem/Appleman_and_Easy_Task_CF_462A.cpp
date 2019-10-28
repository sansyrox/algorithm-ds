// Link to problem : http://codeforces.com/problemset/problem/462/A
#include<iostream>
#include<string>
using namespace std;
int main(){
	int n,flag=0,ctr;
	cin>>n;
	char s[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
			cin>>s[i][j];
		cin.ignore();

	}
	for(int i=0;i<n && flag==0;i++){
		for(int j=0;j<n;j++){
			ctr=0;
			if(s[i][j+1]=='o' && j<n-1)
				ctr++;
			if(s[i][j-1]=='o' && j>0)
				ctr++;
			if(s[i+1][j]=='o'&& i<n-1)
				ctr++;
			if(s[i-1][j]=='o' && i>0)
				ctr++;
			if(ctr%2!=0){
				flag=1;
				break;
			}
		}
	}
	if(flag)
		cout<<"NO";
	else 
		cout<<"YES";

		
	return 0;
	
}