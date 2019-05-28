#include<iostream>
using namespace std;

int minSteps(int n, int coins[], int len){

    if(n<=0) return 0;
    int res = INF;
    
    for(int i=0; i<len; i++){
        if(coins[i]<N){
            int steps = 1 + minSteps(n-coins[i],coins,len);
            if (sub_res < res)
            res = sub_res;
        }
        

    }



}

int main(){
    int n=30;
    int coins[]= {25,10,5};

    cout<<minSteps(n,coins,3);
    return 0;
}