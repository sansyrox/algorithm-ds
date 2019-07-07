#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void indegree(vector<int> adjLis[],int v,int indegree[], int src){
    vector <bool> visited(v+1,false);
    queue<int> q;
    indegree[src] = 0;
    
    for(int i=src; i<=v; i++){
        for(auto x:adjLis[i]){
            indegree[x]++;
            // cout<<indegree[i]<<endl;
        }
    }

}


int main() {
    int n,m;
    cin>>n>>m;
    vector<int> adjLis[n+1];
    int src = INT_MAX;
    for(int i=0; i<m; i++){
        int x,y;
        cin>>x>>y;
        src=min(x,src);
        adjLis[x].push_back(y);
        // adjLis[y].push_back(x);
    }

    int indeg[n+1],outdegree[n+1];
    for(int i=0; i<=n; i++) indeg[i]=0, outdegree[i]=0;
    for(int i=1; i<=n; i++){
        outdegree[i] = adjLis[i].size();
        // cout<<outdegree[i]<<endl;
    }
    indegree(adjLis,n,indeg,src);
    // cout<<outdegree[2]<<endl;
    // cout<<"idahr\n";
    // for(auto i:adjLis[2]){
    //     cout<<i<<" ";
    // }
    // cout<<endl;
    int count=0;
    for(int i=src+1; i<=n; i++){
        if(outdegree[i]>indeg[i]){
            // cout<<i<<endl;
            count++;
        }
    }
    
    cout<<count;
    return 0;
}