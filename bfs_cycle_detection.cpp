#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph{
    map<int, list<int> > adjList;
public:

    void addEdge(int u, int v){
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    bool bfs_cycle_detection(int src){
        queue<int> q;
        map<int,bool> visited;
        map<int, int> parent;
        q.push(src);
        parent[src] = src;
        visited[src] = true;


        while(!q.empty()){
            int T = q.front();
            q.pop();

            for(auto i: adjList[T]){
               if(visited[i]==true and i!=parent[T]){ //
                   return true;
               }

               if(!visited[i]){
                   visited[i] = true;
                   parent[i] = T;
                   q.push(i);
               }
            }
        }

        return false;
    }

    bool isCyclicHelper(int node, map<int, bool> &visited, map<int, bool> &inStack){

        visited[node] = true;
        inStack[node] = true;

        // Explore the neighbours of the node
        for(int neigh: adjList[node]){


            // cuur node is not visited and the forward cycle returns true
            if(!visited[neigh] && (isCyclicHelper(neigh,visited, inStack)||inStack[neigh])){
                return true;
            }

            // Going to pop out the node
            inStack[neigh] = false;
            return false;

        }

    }

    bool dfsIsCyclic(){
        map<int,bool> visited;
        map<int,bool> inStack;

        // To check for cycle in each dfs tree

        for(auto i:adjList){
            int node = i.first;
            if(!visited[node]){
                bool cyclePresent = isCyclicHelper(node,visited, inStack);
                if(cyclePresent) {
                    return true;
                }
            }

            
        }

        return false;
    }


};


int main() {

    return 0;
}