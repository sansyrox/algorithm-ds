#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void spiralPrint(int a[10][10] , int M, int N){

    int D=0, B=M-1, T=0, R=N-1, L=0;
    int i=0,j=0;
    while(L<=R and T<=B) {
        if(D==1) {
            for(int k=L; k<=R; k++) cout<<a[B][k]<<", ";
            B--;
        }

        else if(D==0) {
            for(int k=T; k<=B; k++) cout<<a[k][L]<<", ";
            L++;
        }

        else if(D==2) {
            for(int k=B; k>=T; k--) cout<<a[k][R]<<", ";
            R--;
        }

        else if(D==3){
            for(int k=R; k>=L; k--) cout<<a[T][k]<<", ";
            T++;
        }
        D=(D+1)%4;

    }


}
 
int main() {
   
   int m,n;
   cin>>m>>n;
   int arr[10][10];
   for(int i=0; i<m; i++){
       for(int j=0; j<n; j++){
           cin>>arr[i][j];
        }
    }

    spiralPrint(arr,m,n);
    cout<<"END";

   return 0;
}