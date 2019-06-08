// // RAT CHASES ITS CHEESE
// // You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards left, right, up or down on the grid.
// // Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for. There exits a unique path in the grid . Find that path and help the rat reach its cheese.

// // Input Format:
// // First line contains 2 integers N and M denoting the rows and columns in the grid.
// // Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.


// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mp make_pair
// #define pb push_back

// int noOfPaths(vector<string> arr, int i, int j, int n, int m){
//     // cout<<i<<endl;
//     if(i<0 or j<0){
//         return 0;
//     }

//     if(i>n or j>m){
//         return 0;
//     }

//     if(arr[i][j]=='X'){
//         return 0;
//     }

//     if(i==n and j==m){
//         arr[i][j]='1';
//         for(int i=0; i<=n; i++){
//             for(int j=0; j<=m; j++){
//                 if(arr[i][j]=='X'){
//                     cout<<0<<" ";
//                 }
//                 else if(arr[i][j]!='1') cout<<0<<" ";
//                 else cout<<arr[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         arr[i][j]='0';
//         return 1;
//     }

    

//     int ans =0;
//     arr[i][j]='1';
//         if(arr[i+1][j]=='O')
//             ans+= noOfPaths(arr,i+1,j,n,m);
//         if(arr[i][j+1]=='O')
//             ans+= noOfPaths(arr,i,j+1,n,m);
//         // if(arr[i-1][j]=='O')
//         //     ans+= noOfPaths(arr,i-1,j,n,m);
//         // if(arr[i][j-1]=='O')
//         //     ans+= noOfPaths(arr,i,j-1,n,m);

    
//         arr[i][j]='0'; // not req tho
//     return ans;



// }

// int main() {
    
//     int n,m;
//     cin>>n>>m;
//     vector< string > arr;

//     for(int i=0 ;i<n; i++){
//         string s;
//         cin>>s;
//         arr.push_back(s);
//     }
    
//     int pathFound = noOfPaths(arr, 0,0,n-1,m-1);
//     if(!pathFound) cout<<"NO PATH FOUND";
//     return 0;
// }

// RAT CHASES ITS CHEESE
// You are given an N*M grid. Each cell (i,j) in the grid is either blocked, or empty. The rat can move from a position towards left, right, up or down on the grid.
// Initially rat is on the position (1,1). It wants to reach position (N,M) where it's cheese is waiting for. There exits a unique path in the grid . Find that path and help the rat reach its cheese.

// Input Format:
// First line contains 2 integers N and M denoting the rows and columns in the grid.
// Next N line contains M characters each. An 'X' in position (i,j) denotes that the cell is blocked and ans 'O' denotes that the cell is empty.


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int noOfPaths(vector<string> &arr, int i, int j, int n, int m){
    // cout<<i<<endl;

    if(i>n or j>m){
        return 0;
    }

    if(arr[i][j]=='X'){
        return 0;
    }

    if(i==n and j==m){
        arr[i][j]='1';
        // cout<<endl;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(arr[i][j]=='X'){
                    cout<<0<<" ";
                }
                else if(arr[i][j]!='1') cout<<0<<" ";
                else cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        arr[i][j]='0';
        return 1;
    }

    

    int ans =0;
    arr[i][j]='1';
    if(arr[i+1][j]=='O')
        ans+= noOfPaths(arr,i+1,j,n,m);
    if(arr[i][j+1]=='O')
        ans+= noOfPaths(arr,i,j+1,n,m);
        // if(arr[i-1][j]=='O')
        //     ans+= noOfPaths(arr,i-1,j,n,m);
        // if(arr[i][j-1]=='O')
        //     ans+= noOfPaths(arr,i,j-1,n,m);

    
        arr[i][j]='0'; // not req tho
    return ans;



}

int main() {
    
    int n,m;
    cin>>n>>m;
    vector< string > arr;

    for(int i=0 ;i<n; i++){
        string s;
        cin>>s;
        arr.push_back(s);
    }
    
    int pathFound = noOfPaths(arr, 0,0,n-1,m-1);
    if(!pathFound) cout<<-1;
    return 0;
}



#include<iostream>
#define nn 1001
using namespace std;

bool v[nn][nn],sol[nn][nn];
char maze[nn][nn];
int n,m;
bool solveMaze(int i,int j){
    ///Base Case
    if(i==m && j==n){

        sol[i][j] = 1;

        ///Print the soln
        for(int x=0;x<=m;x++){
            for(int y=0;y<=n;y++){
                cout<<sol[x][y]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(v[i][j])
        return false;
    v[i][j]=1;
    ///Recursive Case
    ///Assuming path exists from i,j
    sol[i][j] = 1;
    ///1. Go Right
        if(j+1<=n && !v[i][j+1]){
                bool pathMila = solveMaze(i,j+1);
                if(pathMila==true){
                    return true;
                }
        }
    /// 2. Go Down
        if(i+1<=m && !v[i+1][j]){
                bool pathMila = solveMaze(i+1,j);
                if(pathMila==true){
                    return true;
                }
        }

    /// Yahan aane se path nahin mila !
    ///Backtracking
    sol[i][j] = 0;
    return false;


}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("input1.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>maze[i][j];
            if(maze[i][j]=='X')
                v[i][j]=1;
        }
    }
    m--;
    n--;
    int ans =solveMaze(0,0);
    if(ans==false){
        cout<<"-1";
    }
    return 0;
}