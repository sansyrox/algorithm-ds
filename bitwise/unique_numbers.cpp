#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int findFirstSetBit(int xor_sum){
	int i=-1;
	while(xor_sum){
		i++;
		if((xor_sum&1) !=0 ) return i;
		xor_sum=xor_sum>>1;
	}
}

int main() {
	int n; cin>>n;
	int arr[n];

	for(int i=0; i<n; i++) {
		cin>>arr[i];
	}

	int xor_sum=0;

	for(auto j:arr){
		xor_sum^=j;
	}

	// cout<<xor_sum<<" XOR SUM \n";
	int index = findFirstSetBit(xor_sum);
	// cout<<index<<" Index hai ye\n";
	int x=0;
	for(auto j:arr){
		if(((j>>index)&1)!=0){
			x^=j;
		}
	}

	int secondNumber = xor_sum^x;
	cout<<x<<" "<<secondNumber;
	return 0;
}