#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph{
    map<int , list<pair<int,int> > > adjList;
    public:

    void addEdge(int u, int v, int d){
        adjList[u].pb(mp(v,d));
        adjList[v].pb(mp(u,d));
    }

    void dijkstras(int src){
        map<int, int> distance;
        set<pair<int, int> > s;
        for(auto i:adjList) distance[i.first] = INT_MAX;
        distance[src] = 0;
        s.insert(mp(0,src));

        while(!s.empty()){
            auto f = *(s.begin());
            int parent = f.second;
            int dist = f.first;
            s.erase(s.begin());
            for(auto i:adjList[parent]){
                if(dist + i.second<distance[i.first]){
                    auto f = s.find(mp(distance[i.first], i.first));

                    if(f!=s.end()){
                        s.erase(f);
                    }

                    s.insert(mp(dist + i.second, i.first));
                }
            }
        }
    }

};


int main() {
    
    return 0;
}