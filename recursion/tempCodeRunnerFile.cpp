#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int board[10][10];

bool isValid(int n,int row, int col){
    // vertical
    for(int i=0; i<col; i++){
        if(board[row][i]==1){
            return false;
        }
    }

    // horizontal
    for(int i=0; i<row; i++){
        if(board[i][col]==1){
            return false;
        }
    }

    // left diag
    int x=row;
    int y=col;

    while(x>=0 and y>=0){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y--;
    }

    // right diagonal
    x=row,y=col;

    while(x>=0 and y<n){
        if(board[x][y]==1){
            return false;
        }
        x--;
        y++;
    }

    return true;
}

bool NQueen(int n, int row=0){
    // cout<<"IDHAR  "<<endl;
    if(row==n){
        cout<<endl;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return 1;
    }

    int sum=0;
    for(int col=0; col<n; col++){
        // cout<<"IDHAR  "<<endl;
        if(isValid(n,row,col)){
            // cout<<row<<"  "<<col<<endl;
            board[row][col]=1;
            int newxtQueen = NQueen(n,row+1);
            sum+=newxtQueen;
            board[row][col]=0;
        }
    }

    return sum;

}

int main() {
    int n;
    cin>>n;
    memset(board,0,sizeof(board));
    cout<<NQueen(n);

    return 0;
}