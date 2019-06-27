#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph{
    // first param is the name
    map<int , list< pair<int, int> > > adjList;
    public:

    void addEdge(int u, int v, int dist, bool bidir){
        adjList[u].push_back(make_pair(v,dist));
        if(bidir){
            adjList[v].push_back(make_pair(u,dist));
        }
        return;
    }


    void dijkstrasSSSP(int src){
        map<int, int> dist;
        // map<int, int> visited;

        // first param is dist
        set<pair<int, int> > s;

        for(auto i:adjList){
            dist[i.first] = INT_MAX;
        }
        s.insert(make_pair(0, src));
        dist[src] = 0;

        while(!s.empty()){
            auto f = *(s.begin());
            int node = f.second;
            int nodeDist = f.first;

            for(auto neighbour: adjList[node]){

                if(s.find(make_pair(dist[neighbour.first], neighbour.first)) != s.end()){
                    s.erase(s.find(make_pair(dist[neighbour.first], neighbour.first)));
                }

                dist[neighbour.first] = min(dist[neighbour.first], nodeDist+neighbour.first);
                s.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }


        // traverse the map
    }

};

int main() {
    
    return 0;
}