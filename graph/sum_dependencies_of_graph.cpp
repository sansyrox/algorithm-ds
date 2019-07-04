// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mp make_pair
// #define pb push_back
// #define vvi vector<vector<int> >
// // class Graph{
// //     map
// // public:
// // };

// int sumOfOutDegree(vvi &G){
//     int count=0;

//     for(auto i:G){
//         for(auto j:i){
//             count++;
//         }
//     }

//     return count;
// }

// int main() {
//     int t; cin>>t;
//     while(t--){
        
//         int n,e;
//         cin>>n>>e;
//         vvi G(n);
//         for(int i=0; i<e; i++){
//             int a,b;
//             cin>>a>>b;
//             G[a].pb(b);
//         }

//         cout<<sumOfOutDegree(G)<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
bool isPossible(vector<vector<int> > &board,int n,int row,int col){
	for(int i=row-1;i>=0;i--){
		if(board[i][col]==1)
			return false;
	}
	// Upward Left Diagonal
	for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
		if(board[i][j]==1)
			return false;
	}
	// Upward right diagonal
	for(int i=row-1,j=col+1;i>=0&&j<=n;i--,j++){
		if(board[i][j]==1)
			return false;
	}
  	return true;
}
void NQueensHelper(vector<vector<int> > &board,int n,int row){
	if(row==n){
        // cout<<"Idhar\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout<<board[i][j]<<" ";
			}
            cout<<endl;
		}
		cout<<endl;
		return;
	}
	// Place the queens and move to the smaller problems
	for(int i=0;i<n;i++){
		if(isPossible(board,n,row,i)){
			board[row][i] = 1;
			NQueensHelper(board,n,row+1);
		}
        board[row][i] = 0; // The backtracking step
	}
	return;
}
void placeNQueens(int n){
   	vector<vector<int> > board(n,vector<int>(n,0));
	NQueensHelper(board,n,0);
}
int main(){
	int n;
	cin>>n;
	placeNQueens(n);
}