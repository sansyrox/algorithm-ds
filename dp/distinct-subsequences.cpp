#include<iostream>
using namespace std;

int distinct_subsequencce(string s1,string s2, int i, int j){
    // base case
    if(i==0){
        return 0;
    }

    if(j==0) return 0;

    if(s1[i]==s2[j] and i!=j){
        return 1+distinct_subsequencce(s1,s2,i-1,j-1);
    }

    return 
        max(
            distinct_subsequencce(s1,s2,i,j-1),
            distinct_subsequencce(s1,s2,i-1,j)
        );


}

int main(){

    cout<<distinct_subsequencce("rabbbit","rabbit",7,6);
    return 0;
}