#include<iostream>
using namespace std;

int blocked[1001][1001] = {0};

// n-1 and m-1
int noOfPaths(int m, int n) {
    if(m==0 or n==0){ // or and and main ek baar check kar lio
        return 1;
    }

    if(blocked[m-1][n]!=0){
        return noOfPaths(m,n-1);
    }

    if(blocked[m][n-1]!=0){
        return  noOfPaths(m-1,n);
    }

    // if(m==0 and n!=0){
    //     return noOfPaths(m,n-1,blocked);
    // }

    // if(m!=0 and n==0) {
    //     return noOfPaths(m-1,n,blocked);
    // }

    return noOfPaths(m-1,n) + noOfPaths(m,n-1);
    

}

int main() {

    int m,n,p;
    cin>>m>>n>>p;
    int blocked[m][n];

    // memset(blocked,0,sizeof(blocked));

    while(p--) {
        int a,b;
        cin>>a>>b;
        blocked[a][b] = -1;
    }

    cout<<noOfPaths(m-1,n-1);

    return 0;
}