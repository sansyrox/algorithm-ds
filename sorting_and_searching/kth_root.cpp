// KTH ROOT
// You are given two integers n and k. Find the greatest integer x, such that, x^k <= n.
// Input Format:
// First line contains number of test cases, T. Next T lines contains integers, n and k.
// Constraints:
// 1<=T<=10 1<=N<=10^12 1<=K<=10^4
// Output Format
// Output the integer x
// Sample Input
// 2 10000 1 1000000000000000 10
// Sample Output
// 100000 31

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

ll binarySearch(ll n, ll k){
    ll s = 1,e=n;
    ll ans = s;
    while(s<=e){
        ll mid = (s+e)/2;
        if(pow(mid,k)<n){
            ans = mid;
            s= mid+1;
        }
        else if(pow(mid,k)>n){
            e = mid-1;
        }
        else {
            return ans=mid;
        }
    }

    return ans;
}

int main() {
    int t; cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        cout<<binarySearch(n,k)<<endl;
    }
    
    return 0;
}