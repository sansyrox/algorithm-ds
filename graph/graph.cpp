#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph{
    map<int, list<pair<int, int> > > adjList;

    public:

        void addEdge(int u, int v, int dist, bool bidir=true){
            adjList[u].push_back(make_pair(v,dist));
            if(bidir){
                adjList[v].push_back(make_pair(u,dist));
            }
        }

        void printAdj(){
            // Let's try to print the adjList
            // Iterate over all the key value pairs over the map

            for(auto j:adjList){
                cout<<j.first<<"->";
                for(auto i :j.second){
                    cout<<"City Name "<<i.first<<", City Distance"<<i.second;
                }
                cout<<endl;
            }
        }


        void dijsktraSSSP(int src){
            map<int, int> dist;
            // Set all distance to infinity
            for(auto j:adjList){
                dist[j.first] = INT_MAX;
            }

            // Make a set to fid out a node with minimum distance
            // first parameter is distance
            set<pair<int, int> >s;
            dist[src] = 0;
            s.insert(make_pair(0,src));

            while(!s.empty()){
                // Find the pair at front
                auto p = *(s.begin());
                int node = p.second;

                int nodeDist = p.first;

                s.erase(s.begin());

                // iterate over neighbours/children of the current node
                for(auto childPair:adjList[node]){
                    if(nodeDist + childPair.second < dist[childPair.first]){
                       
                        // udate in set not possible and hence update and remove
                        auto f = s.find(make_pair(dist[childPair.first], childPair.first));

                        if(f!=s.end()){
                            s.erase(f);
                        }
                        dist[childPair.first] = min(nodeDist+childPair.second, dist[childPair.first]);
                        s.insert(make_pair(dist[childPair.first],childPair.first));
                        // Insert a new pair
                        // distance[]
                    }
                    
                }


                for(auto d:dist){
                    cout<<d.first<<" is located at "<<d.second<<" from "<<src;
                }
            }


        }

};

int main() {
    
    return 0;
}