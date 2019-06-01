// ROTATE IMAGE (N X N ARRAY)
// Given a 2D array of size N x N. Rotate the array 90 degrees anti-clockwise.

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
void transpose(vector< vector<int> > &A){
    // vector< vector<int> > V = A;
    int n = A.size();

    for(int i=0; i<n; i++){
        for(int j=0; j<(n-1)-i; j++) {
            swap(A[i][j], A[n-1-j][n-1-i]);
        }
    }

    for(int i=0; i<n; i++){
        reverse(A[i].begin(),A[i].end());
    }

    for(auto i:A){
        for(auto x:i) {
            cout<<x<<" ";
        }cout<<endl;
    }
}

int main() {
   
   int n; 
   cin>>n;
   vector< vector<int> > a;
   for(int i=0; i<n; i++){
       vector<int> temp;
       for(int j=0; j<n; j++) {
           int t; cin>>t;
           temp.push_back(t);
       }
        a.push_back(temp);
    }

    transpose(a);

   return 0;
}