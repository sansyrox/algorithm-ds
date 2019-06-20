#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph{
    map<int, list<int> > adjList;
public:

    void addEdge(int u, int v, bool bidir=true){
        adjList[u].pb(v);
        if(bidir){
            adjList[v].pb(u);
        }
    }

    void bfs(int src){
        map<int,int> distance;
        queue<int> q;
        q.push(src);
        distance[src] = 0;

        while(!q.empty()){
            int t = q.front();
            cout<<t<<endl; 
            q.pop();
            for(auto i:adjList[t]){
                if(distance.count(i)==0){
                    distance[i] = distance[t]+1;
                }    
            }
            
        }
    }

    void dfsHelper(int src, map<int,bool> &visited){
        if(visited[src]){
            return;
        }

        cout<<src<<" ";

        for(auto i:adjList[src]){
            if(!visited[i]){
                visited[i] = true;
                dfsHelper(i,visited);
            }
        }

    }

    void dfs(int src){
        map<int, bool> visited;
        dfsHelper(src,visited);
    }

    void dfsHelper(int src, map<int,bool> &visited, list<int>& ordering){
        visited[src] = true;

        for(int neigh: adjList[src]){
            if(!visited[neigh]){
                dfsHelper(neigh,visited,ordering);
            }
        }

        // Add 1 line for TS
        // At this point , all childer of current node have been visited
        ordering.push_front(src);
    }

    void dfsTopologicalSort(){
        map<int,bool> visited;
        list<int> orderig;

        for(auto i: adjList){
            // i is a pair of Node, followed by the list of nodes
            int Node = i.first;
            if(!visited[Node]){
                dfsHelper(Node,visited,orderig)
            }
        }

        for(int el: orderig){
            cout<<el<<"->";
        }
    }




    void topoogicalSort(){
        queue<int> q;
        map<int,bool> visited;
        map<int, int> indegree;

        for(auto i:adjList){
            int t = i.first;
            visited[t] = false;
            indegree[t] = 0;
        }


        // .. calculatig the indegree
        for(auto i:adjList){
            int u = i.first;
            for(int v:adjList[u]){
                indegree[v]++;
            }
        }
        // find out all nodes wit indegree

        for(auto i:adjList){
            int node = i.first;
            if(indegree[node]==0){
                q.push(node);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cout<<node<<"->";
            for(int neigh: adjList[node]){
                indegree[node]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
    }
};


int main() {
    
    return 0;
}  