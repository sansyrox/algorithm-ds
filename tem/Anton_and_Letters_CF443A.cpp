// Link to problem :http://codeforces.com/problemset/problem/443/A
#include<iostream>
#include<set>

using namespace std;
int main(){
	string s;
	getline(cin,s);
		set<char>g;
	for(int i=0;i<s.length();){
		if(s[i]=='{' || s[i]=='}'){
			++i;
			continue;
		}
		g.insert(s[i]);
		i+=3;
	}
	cout<<g.size();


	return 0;
}
