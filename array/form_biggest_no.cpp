// FORM BIGGEST NUMBER
// You are provided an array of numbers. You need to arrange them in a way that yields the largest value.

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of array A[] and next line contains n space separated integers A[i] .

#include<iostream>
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int comparator(string a, string b) {
	string AB="",BA="";
	AB += a + b;
	BA += b + a;

	ll ABll = stoll(AB);
	ll BAll = stoll(BA);

	if(ABll>BAll) {
		return 1;
	} else return 0;
}

string maxNumber(vector<string> &s) {
	sort(s.begin(),s.end(),comparator);
    string x="";
    for(auto i:s) x+=i;
	
    return x;
}


int main() {
	vector<string> s;
	int t;cin>>t;
	while(t--){
		// cout<<"Idahr\n";
		int n;cin>>n;
		for(int i=0; i<n; i++) {
			string x;cin>>x;
			s.push_back(x);
		}
		cout<<maxNumber(s)<<endl;
		s.clear();

	}

	return 0;
}