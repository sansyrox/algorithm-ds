#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph{
    list<int> *l;
    int V;
public:
    Graph(int v){
        V = v;
        l = new list<int>[V]; 
    }

    void addEdge(int u, int v){
        l[u].pb(v);
        l[v].pb(u);
    }

    bool isBipartite(int s){
        queue<int> q;
        q.push(s);

        int *colors = new int[V];
        for(int i=0; i<V; i++){
            colors[i] = -1; // Not visited
        }

        colors[s] = 0;
        bool ans = true;
        while(!q.empty() and ans){
            int u = q.front();
            q.pop();

            for(auto v:l[u]){
                if(colors[v]==-1){
                    colors[v] = 1 -colors[u];
                    q.push(v);
                }
                else if(colors[v]==colors[u]){
                    ans = false;
                    break;
                }
            }
        }


    return ans;
    }

};

int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(2,0);
    g.addEdge(1,3);
    g.addEdge(2,3);

    cout<<g.isBipartite(0);

    return 0;
}