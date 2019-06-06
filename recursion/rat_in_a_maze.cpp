#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int noOfWays(int maze[][10], int i,int j, int m, int n){
    if(i==m and j==n){
        for(int x=0; x<n; x++){
            for(int y=0; y<m; y++){
                cout<<maze[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return 1;
    }
    if(i>m or j>n) return 0;

    if(maze[i][j]==-1) return 0;

    if(maze[i][j]== 1) return 0;
    
    maze[i][j] = 1;
    int ans = noOfWays(maze,i+1,j,m,n) + noOfWays(maze,i,j+1,m,n);
    maze[i][j] = 0;

    return ans;
    
}

int main() {
    int maze[10][10]={0};
    int m,n;
    cin>>n>>m;
    int ans = noOfWays(maze,0,0,m,n);
    cout<<ans<<endl;
    return 0;
}