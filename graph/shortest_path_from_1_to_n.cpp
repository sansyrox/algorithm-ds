#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Graph{
    map<int, list<int> > adjList;
    map<int,bool> visited;
    
public:
    map<int,int> distance;
    void addEdge(int u, int v){
        adjList[u].pb(v);
    }

    void bfsSSP(int src){
        

        queue<int> q;

        // for(int i=1; i<=1001;i++){
        //     distance[i] = INT_MAX;
        // }

        distance[src] = 0;
        visited[src] = true;
        q.push(src);
        // cout<<distance[1]<<endl;

        for(auto i:adjList){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ";
            }
            cout<<endl;
        }

        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(auto neigh:adjList[t]){
                if(distance.count(neigh)==0){
                    q.push(neigh);
                    visited[neigh] = true;
                    distance[neigh] = distance[t] + 1;
                }
            }
        }

        // return distance[dest];

    }
};




int main() {
    Graph G;
    for(int i=1; i<10001; i++){
            G.addEdge(i,i+1);
            G.addEdge(i,3*i);

    }
    G.bfsSSP(1);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        // cout<<<<endl;
        cout<<G.distance[n]<<endl;
    }


    return 0;
}