// Given an n x m matrix, where every row and column is sorted in increasing order, and a number x . Find if element x is present in the matrix or not.

// Input Format:
// First line consists of two space separated integers N and M, denoting the number of element in a row and column respectively. Second line of each test case consists of N*M space separated integers denoting the elements in the matrix in row major order. Third line of each test case contains a single integer x, the element to be searched.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search(vector<vector<int> > a, int x, int n, int m){
    int i=0; int j = m-1;

    while(i<n and j<m and i>=0 and j>=0){
        if(x>a[i][j]){
            i++;
        }
        else if(x<a[i][j]){
            j--;
        }
        else {
            return 1;
        }
    }

    return 0;
}

int main() {

    int t=1;
    while(t--) {
    int n,m;
    cin>>n>>m;
    vector<vector<int> > arr;
    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<m; j++) {
            int t; cin>>t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }
    int k; cin>>k;
    cout<<search(arr,k,n,m)<<endl;

    }

    
	return 0;
}