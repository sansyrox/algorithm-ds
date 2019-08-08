#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


void multiply(vector<int> &A, vector<int> &B){
    vector<int> O(1000000,0);
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    int carry = 0;
    int st_i=0;
    int prev=0;
    for(int i=0; i<B.size(); i++){
        for(int j=0; j<A.size(); j++){
            int prod = A[j]*B[i] + carry +O[st_i];
            // cout<<prod<<endl;
            carry = prod/10;
            O[st_i] += prod%10; 
            // cout<<O[st_i]<<" \n";
            st_i++;
        }

    // exit(0);
        st_i=prev+1;
        prev++;
    }

    cout<<prev<<"  "<<carry<<endl;

    for(int i=prev-1; i>=0; i--){
        cout<<O[i];
    }
    cout<<endl;

    return;
}


int main() {
    int t; cin>>t;
    while(t--){
        cpp_int a,b;
        cin>>a>>b;
        
        cout<<a*b<<endl;
    }


    return 0;
}