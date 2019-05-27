// Given a number say 21 . you have to find a to bring it to 1 in min steps
// 3 options : /3, /2 , -1
// 

#include<iostream>
using namespace std;

const int inf = (int)1e9;


int dp[1001];

int minSteps(int n){

    int n3=inf,n2=inf,n1=inf;
    if(n==1) return 0;

    if(n%3==0) n3=1+minSteps(n/3);
    if(n%2==0) n2=1+minSteps(n/2);
    
    n1 = 1+minSteps(n-1);

    if(dp[n]!= -1) return dp[n];

    dp[n] = min(n3,min(n1,n2));;
    return dp[n];

}

int minStepsDP(int n){
    
    // base cases
    dp[0] = 0; dp[2] = 1;
    dp[1] = 0; dp[3] = 1;

    // baaki cases

    for(int i=4; i<=n; i++){
        int q1=inf,q2=inf,q3=inf;

        if(i%3==0) q1 = 1+dp[i/3];
        if(i%2==0) q2 = 1+dp[i/2];

        q3 = 1+dp[i-1];

        dp[i] = min(q1,min(q2,q3));
    }


    return dp[n];
}

int main(){

    for(int i=0; i<=4; i++){
        dp[i] = -1;
    }
    cout<<minSteps(4)<<endl;
    cout<<minStepsDP(4)<<endl;
    return 0;
}