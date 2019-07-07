// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mp make_pair
// #define pb push_back

// class Node{
//     public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int d){
//         data = d;
//         left=right=NULL;
//     }
// };

// Node*  levelOrderip(){
//     int d; cin>>d;
//     Node* root = new Node(d);
//     queue<Node*> q;
//     q.push(root);

//     while(!q.empty()){
//         Node* top = q.front();
//         q.pop();
//         int a,b;
//         cin>>a>>b;
//         if(a!=-1){
//             Node* left = new Node(a);
//             top->left=left;
//             q.push(left);
//         }

//         if(b!=-1){
//             Node* right = new Node(a);
//             top->right=right;
//             q.push(right);
//         }
//     }

//     return root;
// }


// int main() {
    
//     return 0;
// }

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


#define vvi vector<vector<int> >
bool isSafe(vvi &board, int i, int j, int x){
    if(i==0||j==0){
        if(i==0 and j==0){
            return true;
        }
        
        if(i==0){
            return board[i][j-1]!=x;
        }
        
        if(j==0){
            return board[i-1][j]!=x;
        }
    }
    
    
    return board[i-1][j]!=x and board[i][j-1]!=x;
}

int fx(vvi &dp, vvi&board, int i, int j, int n){
    
    
    if(j==n){
        j=0;
        i=i+1;
    }
    
    if(i==3){
        return 1;
    }
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    
    int ma=0;
    for(int x=0; x<4; x++){
        if(isSafe(board,i,j,x)){
            int y = board[i][j];
            board[i][j]=x;
            ma = (ma%1000000007 + fx(dp,board,i,j+1,n)%1000000007)%1000000007;
            board[i][j]=y;
        }
    }
    
    return ma;
}

int main() {
    int A = 87;
    vvi dp(3,vector<int> (A+1,-1));
    vvi board(3,vector<int> (A+1,-1));
    
    cout<<fx(dp,board,0,0,A);

    return 0;
}
