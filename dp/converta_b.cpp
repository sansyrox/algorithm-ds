#include<iostream>
using namespace std;

int dp[1001]={0};

int returnSteps(int a, int b, int c){
    if(a==b){
        return 1;
    }
    if(a>b){
        return returnSteps(a-1,b,c) + returnSteps(a-2,b,c);    
    }
    return returnSteps(a,b/c,c) + returnSteps(a-1,b,c) + returnSteps(a-2,b,c);
}

int main(){

    int t;cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<returnSteps(a,b,c)<<endl;

    }
    return 0;
}