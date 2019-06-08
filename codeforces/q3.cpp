#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool isSorted(vector<ll> a){
    for(ll i=0 ; i<a.size()-1; i++){
        if(a[i]<=a[i+1]){
            return false;
        }
    }
    return true;
}

ll dp[1000001];

ll returnMinSteps(vector<ll> stack, vector<ll> hand, ll i, ll n ){

    if(i>(n<<1)){
        return 1e9;
    }


    if(isSorted(stack)){
        return dp[i]=0;
    }

    if(dp[i]!=-1 and i<1000001) return dp[i];

    ll minStep=1e9;

    for(int x=0; x<n; x++){
        ll t = hand[x];
        stack.pb(t);
        hand[x] = stack.front();
        stack.erase(stack.begin());
        // cout<<"Stack\n";
        // for(auto j:stack){
        //     cout<<j<<" ";
        // }
        // cout<<endl;
        // cout<<"Hand\n";
        // for(auto j:hand){
        //     cout<<j<<" ";
        // }
        // cout<<endl;



        minStep=min(
            minStep,
            1+returnMinSteps(stack,hand,i+1,n)
        );
    }
    
    return dp[i]=minStep;


}

int main() {
    ll n; cin>>n;
    vector<ll> stack,hand;
    for(ll i=0; i<n; i++){
        ll t;
        cin>>t; hand.pb(t);
    }

    for(ll i=0; i<n; i++){
        ll t;
        cin>>t; stack.pb(t);
    }

    for(ll i=0; i<1000001; i++) dp[i]=-1;
    cout<<returnMinSteps(stack,hand,0,n);

    return 0;
}