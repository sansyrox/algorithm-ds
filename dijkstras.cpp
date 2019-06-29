#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

template <typename T>
class Graph{
    map <T, list< pair<T, int> > > adjList;
    vector< vector<int>> A(10,vector<int>(8,-1)) ;
    vector<int> B(4,INT_MAX);
public:

    void addEdge(T u, T v, int dist, bool bidir=true){
        adjList[u].pb(mp(v,dist));
        if(bidir){
            adjList[v].pb(mp(u,dist));
        }
    }

    void printAdj(){
        //Let try to print the adj list
        //Iterate over all the key value pairs in the map 
        for(auto j:adjList){
            cout<<j.first<<"->";
            //Iterater over the list of cities
            for(auto l: j.second){
                    cout<<"("<<l.first<<","<<l.second<<")";       
            } cout<<endl;
        }
    }

    void dijsktraSSSP(T src){
        map<T,int> dist;

        // Set all the distance to infinity
        for(auto j:adjList){
            dist[j.first] = INT_MAX;
        }

        set < pair<int, T> > s;
        dist[src] = 0;
        s.insert(mp(0,src));

        while(!s.empty()){

            auto p = *(s.begin());
            T node = p.second;

            int nodeDist = p.first;
            s.erase(s.begin());


            for(auto neighbour:adjList[node]){
                if(nodeDist + neighbour.second < dist[neighbour.first]){

                    T dest = neighbour.first;
                    auto f = s.find(mp(dist[dest],dest));
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    dist[dest] = nodeDist + neighbour.second;
                    s.insert(make_pair(dist[dest],dest));

                }
            }

            




        }for(auto d:dist){
            
            cout<<d.first<<" is located at distance of  "<<d.second<<endl;
        }
    }





};


int main() {
    
    Graph<int> g;
    g.addEdge(1,2,1);
    g.addEdge(1,3,4);
    g.addEdge(2,3,1);
    g.addEdge(3,4,2);
    g.addEdge(1,4,7);
    //g.printAdj();
   // g.dijsktraSSSP(1);
    
    
    
    
    Graph<string> india;
    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);
    //india.printAdj();
    india.dijsktraSSSP("Amritsar");

    return 0;
}