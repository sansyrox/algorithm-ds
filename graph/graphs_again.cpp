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
        return;
    }

    void bfs(int src){
        queue<int> q;
        map<int,bool> visited;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            cout<<q.front();
            int t = q.front();
            q.pop();
            for(auto i:adjList[t]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }

        }
    }

    void dfsHelper(int src, map<int, bool> &visited){
        // if(visited[src]){
        //     return;
        // }

        cout<<src<<" ";
        visited[src]=true;

        for(auto i:adjList[src]){
            if(!visited[i]){
                dfsHelper(i,visited);
            }

        }
    }

    void dfs(int src){
        map<int, bool> visited;
        dfsHelper(src,visited);
    }


    void topSortDfsHelper(int src, map<int,bool> &visited, list<int> &finalArray){
        cout<<src<<" ";
        visited[src]=true;

        for(auto i:adjList[src]){
            if(!visited[i]){
                dfsHelper(i,visited);
            }

        }

        finalArray.push_front(src);
    }


    void dfsTopologicalSort(int src){
        map<int, bool> visited;
        list<int> finalArray;
        for(auto i:adjList){
            int node = i.first;
            if(!visited[node]){
                topSortDfsHelper(src,visited, finalArray);
            }
        }

    }


    void topologicalSortBFS(){
        queue<int> q;
        map<int,bool> visited;
        // map<int, int> parent;
        map<int, int> indegree;
        vector<int> arr;
        for(auto i:adjList){
            int t = i.first;
            indegree[t] = 0;
        }

        for(auto i:adjList){
            for(auto j:i.second){
                indegree[j]++;
            }
        }

        for(auto i:adjList){
            int t = i.first;

            if(indegree[t] == 0){
                q.push(t);
            }
        }


        while(!q.empty()){
            int t = q.front();
            q.pop();
            arr.pb(t);
            for(auto i:adjList[t]) {
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                }
            }
        }

        for (auto i:arr) cout<<i<<" "<<endl;

    }
};


int main() {

    return 0;
}