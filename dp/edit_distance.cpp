#include<iostream>
using namespace std;

int editDistance(string A, string B, int i, int j){
    if(i==0 and j==0){
        return 0;
    }

    if(i==0){
        return j;
    }
    
    if(j==0){
        return i;
    }
    
    if(A[i-1]==B[j-1]){
        return editDistance(A,B,i-1,j-1);
    }
    
    return 1+min(
        editDistance(A,B,i-1,j-1),
        min(
            editDistance(A,B,i-1,j),
            editDistance(A,B,i,j-1)
        )
        );
}


int main(){

    string a="a",b="b";
    cout<<editDistance(a,b,a.length(),b.length());

    return 0;
}