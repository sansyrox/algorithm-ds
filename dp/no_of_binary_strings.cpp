// COUNT NUMBER OF BINARY STRINGS
// You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.
//

#include<iostream>
#include<vector>

using namespace std;

long long returnCount(int n){
    long long a[n], b[n]; 
    a[0] = b[0] = 1; 
    for (int i = 1; i < n; i++) 
    { 
        a[i] = a[i-1] + b[i-1]; 
        b[i] = a[i-1]; 
    } 
    return a[n-1] + b[n-1]; 
}


int main() {
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<returnCount(n)<<endl;
    }
	return 0;
}