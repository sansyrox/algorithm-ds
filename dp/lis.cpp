#include<iostream>
using namespace std;

int lis(const vector<int> &A){
    vector<int> arr = A;
    
    int N= A.size();
    
    vector<int>dp(N+1);

    for(int i=0;i<N;i++) dp[i]=1;

    for(int i=0; i<N; i++){
        for(int j=0; j<=i; j++){
            if(arr[i]>arr[j] and dp[i]<dp[j]+1){
                dp[i] = dp[j]+1;
            }
        }
    }

    return *max_element(dp.begin(),dp.end());


}


int main(){

    vector<int>arr ={0, 2, 6, 13 ,9 , 15};

    cout<<lis(arr);

    return 0;
}