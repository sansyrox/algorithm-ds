#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

// template <typename T>
class Graph{
    map<int, list<int> > m;
public:
    void addEdge(int u, int v){
        m[u].pb(v);
        m[v].pb(u);
    }

    void bfs(int src, int n){
        queue<int> q;
        map<int, int> distance;

        q.push(src);
        distance[src] = 0;

        while(!q.empty()){
            int T = q.front();
            q.pop();
            for(auto i: m[T]){
                if(distance.count(i)==0){
                    q.push(i);
                    distance[i] = distance[T] + 6;
                }
            }
        }

        vector<int> v;
        for(auto i:m){
            if(i.first==src) continue;
            
            if(distance.count(i.first)==0){
                v.pb(-1);
            }
            else {
                v.pb(distance[i.first]);
            }
        }
        
        for(int i=0; i<v.size(); i++){
            cout<<v[i];
            if(i!=v.size()-1) cout<<" ";
        }

    }

};


int main() {
    int q; cin>>q;
    while(q--){
        int n,m;
        cin>>n>>m;
        Graph g;
        int s; cin>>s;
        for(int i=0; i<m; i++) {
            int a,b; cin>>a>>b;
            g.addEdge(a,b);
        }
        g.bfs(s,n);cout<<endl;
    }    
    return 0;
}