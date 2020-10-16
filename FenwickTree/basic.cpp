// This is a basic Fenwick tree (or Binary Indexed Tree) 
#include <bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define int long long
#define ff first
#define ss second
#define loop(i,k,n) for(int i=k;i<n;++i)
#define rloop(i,n,k) for(int i=n;i>=k;i--)
#define vi vector<int>
#define vvi vector<vector<int> >
#define vpii vector<pair<int,int> >
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
struct fenwick_tree{
public:
    vi f;
    int n;
    void init(int n){
        this->n = n+1;
        f.resize(n+1,0);
    }
    // return sum from [1,x]
    int sum(int x){
        int ans = 0;
        x++; // Due to 0 based indexing of array
        for(int xx = x;x>0;x -= (x&(-x)))
            ans += f[x];
        // while(x>0){
        //     ans += f[x];
        //     x = x-(x&(-x));
        // }
        return ans;
    }
    // add value to index x
    void add(int x,int val){
        x++;
        while(x<n){
            f[x] += val;
            x = x+(x&(-x));
        }
    }
    int sum(int l,int r){
        return sum(r)-sum(l-1);
    }

};

void solve(){
    int n;
    cin>>n;
    fenwick_tree bit;
    bit.init(n);
    int a[n];
    loop(i,0,n) {
        cin>>a[i];
        bit.add(i,a[i]);
    }
    cout<<bit.sum(0)<<endl;
    cout<<bit.sum(3)<<endl;
    cout<<bit.sum(2,4)<<endl;
}

int32_t main(){
    get_it_done();
    int tc=1;
    // cin >> tc;
    while (tc--){
        solve();        
    }
}
