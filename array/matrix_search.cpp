// Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . Find if element x is present in the matrix or not.

// Input Format:
// First line consists of two space separated integers N and M, denoting the number of element in a row and column respectively. Second line of each test case consists of N*M space separated integers denoting the elements in the matrix in row major order. Third line of each test case contains a single integer x, the element to be searched.

#include<iostream>
using namespace std;
int main() {

    int t; cin>>t;
    while(t--) {
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++) {
            cin>>arr[i][j];
        }
    }
    int k; cin>>k;

    int i,j;

    for( i=0; i<n; i++){
        if(k<arr[i][0] || k>arr[i][m-1]) {
            continue;
        }
        for( j=0; j<m; j++) {
            if(k==arr[i][j]) {
                cout<<1<<endl;break;
            }
        }
    }

    if(i==n and j== m) {
        cout<<0<<endl;
    }

    }

    
	return 0;
}