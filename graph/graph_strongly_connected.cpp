#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define vvi vector<vector<int> >

class Graph{
    int V;
    vvi adjList;
public:
    Graph(int v){
        V = v;
        vvi temp(V);
        adjList = temp;
    }

    void addEdge(int u, int v){
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    void dfsHelper(int src,vector<bool> &visited){
        cout<<src<<" ";
        visited[src] = true;
        for(auto i:adjList[src]){
            // for(auto j:i)
            if(!visited[i]){
                dfsHelper(i,visited);
            }
        }
    }

    void dfs(int src){
        vector<bool> visited;
        dfsHelper(src,visited);
    }

    void transpose(){
        vvi adjList2(V);
        for(int i=0; i<adjList.size(); i++){
            for(int j=0; j<adjList[i].size(); j++){
                adjList[adjList[j]].pb(i);
            }
        }

        adjList = adjList2;

    }

    bool kosoRaju(int src){
        dfs(src);
        transpose();
        dfs(src);
    }
};


int main() {
    
    return 0;
}