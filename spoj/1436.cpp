#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph {
    map<int, list<int> > adjList;
    public:

    void addEdge(int u, int v){
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    bool cycle(int src) {
        map<int,bool> visited;
        map<int, int> parent;

        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = true;

        while(!q.empty()){
            int t = q.front();
            q.pop(); 

            for(auto i:adjList[t]){
                if(visited[i] and parent[t]!=i){
                    return true;
                }
                else if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                    parent[i] = t;
                }
            }
        }

        return false;
    }

    void dfsHelper(int src, map<int,bool> &visited){
        if(visited[src]){
            return;
        }

        visited[src] = true;
        for(auto i:adjList[src]){
            dfsHelper(i,visited);
        }
    }

    int connected_components(int src){
        map<int, bool> visited;
        int count = 1;
        dfsHelper(src,visited);

        for(auto i:adjList){
            int t = i.first;
            if(!visited[t]){
                count++;
                dfsHelper(t,visited);
            }
        }


        return count;
    }

};


int main() {
    Graph g;
    int m,n;
    cin>>m>>n;
    while(n--){
        int u,v;
        cin>>u>>v;
        g.addEdge(u,v);
        
    }

    if(g.connected_components(1)>1 || g.connected_components(1)==0){
        cout<<"NO\n";
    }

    else if(g.cycle(1)){
        cout<<"NO\n";
    }
    else {
        cout<<"YES\n";
    }
    return 0;
}