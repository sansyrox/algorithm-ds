// https://www.codechef.com/problems/MULTQ3
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
const int N = 4e5+5;
struct node{
    int arr[3]={0};
};
int n,q;
int lazy[N];
node st[N];

void buildTree(int s,int e,int idx){
    if(s==e){
        st[idx].arr[0] = 1;
        st[idx].arr[1] = 0;
        st[idx].arr[2] = 0;
        return;
    }
    int mid = (s+e)/2;
    buildTree(s,mid,2*idx);
    buildTree(mid+1,e,2*idx+1);
    st[idx].arr[0] = (st[2*idx].arr[0]+st[2*idx+1].arr[0]);
    st[idx].arr[1] = (st[2*idx].arr[1]+st[2*idx+1].arr[1]);
    st[idx].arr[2] = (st[2*idx].arr[2]+st[2*idx+1].arr[2]);
    return;
}

void shift(int idx){
    int temp = st[idx].arr[2];
    st[idx].arr[2] = st[idx].arr[1];
    st[idx].arr[1] = st[idx].arr[0];
    st[idx].arr[0] = temp;
}

void updateTree(int s,int e,int l,int r,int idx){
    if(lazy[idx]!=0){
        int add = lazy[idx];
        add %= 3;
        lazy[idx] = 0;
        loop(i,0,add){
            shift(idx);
        }
        if(s!=e){
            lazy[2*idx] += add;
            lazy[2*idx+1] += add;
        }
    }
    if(s>r || e<l) return;
    if(s>=l && e<=r){
        shift(idx);
        if(s!=e){
            lazy[2*idx] += 1;
            lazy[2*idx+1] += 1;
        }
        return;
    }
    int mid = (s+e)/2;
    updateTree(s,mid,l,r,2*idx);
    updateTree(mid+1,e,l,r,2*idx+1);
    st[idx].arr[0] = (st[2*idx].arr[0]+st[2*idx+1].arr[0]);
    st[idx].arr[1] = (st[2*idx].arr[1]+st[2*idx+1].arr[1]);
    st[idx].arr[2] = (st[2*idx].arr[2]+st[2*idx+1].arr[2]);
    return;
}

int queryTree(int s,int e,int l,int r,int idx){
    if(lazy[idx]!=0){
        int add = lazy[idx];
        add %= 3;
        lazy[idx] = 0;
        loop(i,0,add){
            shift(idx);
        }
        if(s!=e){
            lazy[2*idx] += add;
            lazy[2*idx+1] += add;
        }
    }
    if(s>r || e<l) return 0;
    if(s>=l && e<=r){
        return st[idx].arr[0];
    }
    int mid = (s+e)/2;
    int left = queryTree(s,mid,l,r,2*idx);
    int right = queryTree(mid+1,e,l,r,2*idx+1);
    return left+right;
}


void solve(){
    cin>>n>>q;
    mset(lazy,0);
    buildTree(0,n-1,1);
    while(q--){
        int t,l,r;
        cin>>t>>l>>r;
        if(t==0){
            updateTree(0,n-1,l,r,1);
        }else{
            cout<<queryTree(0,n-1,l,r,1)<<endl;
        }
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
