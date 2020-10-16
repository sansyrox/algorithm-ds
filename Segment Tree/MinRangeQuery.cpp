// This file attempts to solve Range Min query using Segment Tree
#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int,int>>
#define all(v) v.begin(),v.end()
#define mset(a,i) memset(a,i,sizeof(a))
#define mii map<int,int>  
#define pii pair<int,int>
#define deb(...) __f(#__VA_ARGS__, __VA_ARGS__)
#define mp make_pair
#define pb push_back
#define mod 1000000007  
#define endl "\n"
#define inf 1e18

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> pbds1;

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { if(0) return; cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args){   
    if(0) return; 
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}
void get_it_done(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}
int gcd(int a,int b){
    if(b==0) return a;
    if(a<b) return gcd(b,a);
    return gcd(b,a%b);
}
const int N = 3e5+5;

void buildTree(int *arr,int *tree,int s,int e,int idx){
    if(s==e){
        tree[idx] = arr[s];
        return;
    }
    int mid = (s+e)/2;
    buildTree(arr,tree,s,mid,2*idx);
    buildTree(arr,tree,mid+1,e,2*idx+1);
    tree[idx] = min(tree[2*idx],tree[2*idx+1]);
    return;
}

int query(int *tree,int s,int e,int qs,int qe,int idx){
    if(s>=qs && e<=qe){
        return tree[idx];
    }
    if(s>qe || e<qs){
        return inf;
    }
    int mid = (s+e)/2;
    int l = query(tree,s,mid,qs,qe,2*idx);
    int r = query(tree,mid+1,e,qs,qe,2*idx+1);
    return min(l,r);
}
void update(int *tree,int s,int e,int i,int incr,int idx){
    if(s>i || e<i){
        return;
    }
    if(s==e){
        tree[idx] += incr;
        return;
    }
    int mid = (s+e)/2;
    update(tree,s,mid,i,incr,2*idx);
    update(tree,mid+1,e,i,incr,2*idx+1);
    tree[idx] = min(tree[2*idx],tree[2*idx+1]);
    return;
}

void updateRange(int *tree,int s,int e,int l ,int r,int incr,int idx){
    if(l>e || r<s){
        return;
    }
    if(s==e){
        tree[idx] += incr;
        return;
    }
    int mid = (s+e)/2;
    updateRange(tree,s,mid,l,r,incr,2*idx);
    updateRange(tree,mid+1,e,l,r,incr,2*idx+1);
    tree[idx] = min(tree[2*idx],tree[2*idx+1]);
    return;
}

void solve(){
    int arr[] = {1,3,2,-5,6,4};
    int n = sizeof(arr)/sizeof(int);
    int tree[4*n+1];
    buildTree(arr,tree,0,n-1,1);
    int q;
    cin>>q;
    update(tree,0,n-1,3,10,1);
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(tree,0,n-1,l-1,r-1,1)<<endl;
    }
}


int32_t main(){
    get_it_done(); 
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
