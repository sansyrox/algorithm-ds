// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mp make_pair
// #define pb push_back

// int board[10][10];

// bool isValid(int n,int row, int col){
//     // vertical
//     for(int i=0; i<col; i++){
//         if(board[row][i]==1){
//             return false;
//         }
//     }

//     // horizontal
//     for(int i=0; i<row; i++){
//         if(board[i][col]==1){
//             return false;
//         }
//     }

//     // left diag
//     int x=row;
//     int y=col;

//     while(x>=0 and y>=0){
//         if(board[x][y]==1){
//             return false;
//         }
//         x--;
//         y--;
//     }

//     // right diagonal
//     x=row,y=col;

//     while(x>=0 and y<n){
//         if(board[x][y]==1){
//             return false;
//         }
//         x--;
//         y++;
//     }

//     return true;
// }

// bool NQueen(int n, int row=0){
//     // cout<<"IDHAR  "<<endl;
//     if(row==n){
//         cout<<endl;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 cout<<board[i][j]<<" ";
//             }
//             cout<<endl;
//         }
//         return 1;
//     }

//     int sum=0;
//     for(int col=0; col<n; col++){
//         // cout<<"IDHAR  "<<endl;
//         if(isValid(n,row,col)){
//             // cout<<row<<"  "<<col<<endl;
//             board[row][col]=1;
//             int newxtQueen = NQueen(n,row+1);
//             sum+=newxtQueen;
//             board[row][col]=0;
//         }
//     }

//     return sum;

// }

// int main() {
//     int n;
//     cin>>n;
//     memset(board,0,sizeof(board));
//     cout<<NQueen(n);

//     return 0;
// }

#include<iostream>
using namespace std;

bool canPlace(int board[][10],int n,int x,int y){

	//Column
	for(int k=0;k<x;k++){
		if(board[k][y]==1){
			return false;
		}
	}
	//Left Diag
	int i=x,j=y;
	while(i>=0 and j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;j--;
	}

	//Right Diag
	i=x,j=y;
	while(i>=0 and j<n){
		if(board[i][j]==1){
			return false;
		}
		i--; j++;
	}
	return true;
}


int NQueen(int n,int board[][10],int i){
	//Base Case
	if(i==n){
		//Print the board
		for(int x=0;x<n;x++){
			for(int y=0;y<n;y++){
				cout<<board[x][y]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
		return 1;
	}
	//Rec Case
	//Try to place queen at every column/position in the current row
	int cnt = 0;
	for(int j=0;j<n;j++){
		if(canPlace(board,n,i,j)){
			board[i][j] = 1;
			int aageKaCount = NQueen(n,board,i+1);
			cnt += aageKaCount;
			board[i][j] = 0;
		}
	}
	return cnt;
}

int main(){

	int board[10][10] = {0};
	int n;
	cin>>n;

	cout<<NQueen(n,board,0);

	return 0;
}