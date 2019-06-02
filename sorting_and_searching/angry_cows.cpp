// AGGRESSIVE COWS
// Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,…,xN (0 <= xi <= 1,000,000,000).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
// Input Format:
// First line contains N and C, separated by a single space, representing the total number of stalls and number of cows respectively. The next line contains N integers containing the indexes of stalls.
// Constraints:
// Output Format
// Print one integer: the largest minimum distance.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool isValid(ll n, ll pos[], ll c, ll ans){

    ll count =1;
    // int index=0;
    ll prev=pos[0];
    for(ll i=1; i<n; i++) {
        
        if(pos[i]-prev>=ans) {
            count+=1;
            if(count==c)
                return true;
            prev = pos[i];
        }
    }

    return false;


}

ll binarySearch(ll n, ll pos[], ll c) {
    ll s= 0 ; 
    ll e = pos[n-1];
    
    ll ans=-1;

    while(s<=e){
        ll mid = (s+e)/2;
        if(isValid(n,pos,c,mid)){
            ans = mid;
            s=mid+1;
            // cout<<ans<<endl;
        }
        else {
            e = mid-1;
            // cout<<mid<<endl;
        }
    }
    
    return ans;
}

int main() {
    
    // ll arr[5] = {1,2,4,8,9};
    ll t;cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        ll arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];
        sort(arr,arr+n);
        cout<<binarySearch(n,arr,c)<<endl;
    }
    
    return 0;
}