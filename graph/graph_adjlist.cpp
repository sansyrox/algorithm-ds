#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph{

    int V;
    list<int> *l;
public:
    Graph(int v){
        V = v;
        // array of linked lists
        l = new list<int>[V];
    }

    void addEdge(int u, int v, bool bidir=true){
        l[u].pb(v);
        if(bidir){
            l[v].pb(u);
        }
    }

    void printAdjList(){
        for(int i=0; i<V; i++){
            // l[i] is a ll
            for(int vertex:l[i]){ 
                cout<<vertex<<",";
            }
            cout<<endl;
        }
    }


};

int main() {
    Graph g(5);
    g.addEdge(3,4);
    g.addEdge(4,4);
    g.addEdge(2,4);
    g.addEdge(1,4);
    g.addEdge(0,4);
    g.printAdjList();
    return 0;
}