#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define vvi vector<vector <int> >

bool canPlace(vvi board, int r, int c){
    for(int i=0; i<r; i++){
        if(board[i][c]==1) return false;
    }

    for(int i=0; i<c; i++){
        if(board[r][i]==1) return false;
    }

    int i=r,j=c;
	while(i>=0 and j>=0){
		if(board[i][j]==1){
			return false;
		}
		i--;j--;
	}

	//Right Diag
	i=r,j=c;
	while(i>=0 and j<board.size()){
		if(board[i][j]==1){
			return false;
		}
		i--; j++;
	}
	return true;

}

int nQueen(vvi &board, int i, int n){

    if(i==n){
        // cout<<endl;
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         cout<<board[i][j]<<" ";
        //     }cout<<endl;
        // }

        return 1;
    }

    int ans =0;
    for(int j=0; j<n; j++){
        if(canPlace(board, i, j)){
            board[i][j] = 1;
            ans+=nQueen(board,i+1,n);
            
        }
        board[i][j] = 0;
    }

    return ans;


}

int main() {

    vvi board;
    int n;cin>>n;

    for(int i=0; i<n; i++){
        vector<int> t(n,0);
        board.pb(t);
    }


    cout<<nQueen(board,0,n);


    return 0;
}