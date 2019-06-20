#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

template <typename T>
class Graph{
    map<T, list<T> > adjList;

public:
    Graph(){

    }

    void addEdge(T u,T v, bool bidir=true){
        adjList[u].push_back(v);
        if(bidir){
            adjList[v].push_back(u);
        }
    }

    void print(){
        for(auto j:adjList){
            cout<<j.first<<"->";
            for(auto i:j.second){
                cout<<i<<",";
            }
            cout<<endl;
        }
    }

    void bfs(T src){
        queue<T> q;
        map<T,bool> visited;

        q.push(src);
        visited[src] = true;

        while(!q.empty()){
            T node = q.front();
            cout<<node<<" ";
            q.pop();
            // For the neighbours, find out the ndeis which are not visited
            for(int neighbour: adjList[node]){
                if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }

    }

    void ssp(T src){
        queue<T> q;
        map<T,int> distance;

        q.push(src);
        distance[src] = 0;
        cout<<src<<" "<<distance[src]<<endl;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int neigh:adjList[t]){
                if(distance.count(neigh)==0){
                    q.push(neigh);
                    distance[neigh] = distance[t] + 1;   
                }
            }
        }

        for(auto i:distance){
            cout<<i.first<<" "<<i.second<<endl;
        }
    }


    int snakes_and_ladders(T src){
        queue<T> q;
        map<T,int> distance;
        map<T,T> parent;

        q.push(src);
        distance[src] = 0;
        parent[src] = src;
        // cout<<src<<" "<<distance[src]<<endl;
        while(!q.empty()){
            int t = q.front();
            q.pop();
            for(int neigh:adjList[t]){
                if(distance.count(neigh)==0){
                    q.push(neigh);
                    distance[neigh] = distance[t] + 1;   
                    parent[neigh] = t;
                }
            }
        }

        // for(auto i:distance){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }

        // You can start from destination
        T temp = 36;
        while(temp!=src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;


        return distance[36];
    }

    void dfsHelper(T src, map<T,bool> &visited){

        cout<<src<<",";
        visited[src] = true;
        for(auto neigh: adjList[src]){
            if(!visited[neigh])
                dfsHelper(neigh,visited);
        }
    }

    void dfs(T src){
        map<T,bool> visited;
        dfsHelper(src,visited);
    }
};

int main() {
    Graph<int> g;
    int board[50] = {0};
    board[2] = 13;
    board[5] = 7;
    board[9] = 18;
    board[18] = 11;
    board[17] = -13;
    board[20] = -14;
    board[24] = -8;
    board[25] = -10;
    board[32] = -2;
    board[34] = -22;

    for(int u=0; u<=36; u++){
        for(int i=1; i<=6; i++){
            g.addEdge(u,u+i+board[i+u], false);
        }
    }

    // g.print();
    cout<<g.snakes_and_ladders(0);

    g.dfs(0);
    return 0;
}