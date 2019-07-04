#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define vvi vector<vector<int> >

void floodFill(vvi &board, int x, int y, int prev, int curr){
    if(x<0 || y<0|| x>=board.size()||y<=board[0].size()){
        return;
    }

    if(board[x][y]!=prev){
        return;
    }

    board[x][y] = curr;

    floodFill(board,x+1,y,prev,curr);
    floodFill(board,x,y-1,prev,curr);
    floodFill(board,x-1,y,prev,curr);
    floodFill(board,x,y+1,prev,curr);
}

int main() {
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        vvi board;

        for(int i=0; i<n; i++){
            vector<int> t;
            for(int j=0; j<m; j++){
                int x; cin>>x;
                t.pb(x);
            }
            board.pb(t);
        }
        int x,y,k;
        cin>>x>>y>>k;

        floodFill(board,x,y,board[x][y],k);

        for(auto i:board){
            for(auto j:i){
                cout<<j<<" ";
            }
        }
    }
    
    

    return 0;
}