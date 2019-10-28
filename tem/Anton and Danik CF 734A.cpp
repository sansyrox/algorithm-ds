#include<bits/stdc++.h>
using namespace std;

int main(){
	long n;
	int a=0,d=0;
	cin>>n;
	char s;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s==65)
			a++;
		else
			d++;
	}
	if(a>d){
		cout<<"Anton";
	}
	else if(a<d){
		cout<<"Danik";
	}
	else
		cout<<"Friendship";
	return 0;
}