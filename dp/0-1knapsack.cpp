#include<iostream>
using namespace std;

int knapSackProfit(int S, int wt[], int value[], int N) {
    int profit=0;
    if(S==0) return 0;

    for(int i=0; i<N; i++){
        if(wt[i]>0){
            
            S -= wt[i];
            wt[i] = 0;
            
            profit = value[i] + knapSackProfit(S,wt,value,N);
        }
    }

    return profit;
}

int main(){
    int N,S;
    cin>>N>>S;

    int value[N],wt[N];

    for(int i=0;i<N; i++){
        cin>>wt[i];
    }

    for(int i=0;i<N; i++){
        cin>>value[i];
    }

    // for(auto i:value) cout<<i<<" ";

    cout<<knapSackProfit(S,wt,value, N);

    return 0;
}