// #include<iostream>
// using namespace std;

// int knapSackProfit(int S, int wt[], int value[], int N) {
//     int profit=0;
//     if(S==0) return 0;

//     for(int i=0; i<N; i++){
//         if(wt[i]>0){
            
//             S -= wt[i];
//             wt[i] = 0;
            
//             profit = value[i] + knapSackProfit(S,wt,value,N);
//         }
//     }

//     return profit;
// }

#include<iostream>
using namespace std;

int maxKnapSackProfit(int cap, int n, int wt[], int val[]) {
    if(cap == 0 or n==0) {
        return 0;
    }

    if(wt[n-1]>cap) {
        return maxKnapSackProfit(cap, n-1,wt,val);
    }

    return max (
        val[n-1] + maxKnapSackProfit(cap - wt[n-1], n-1, wt, val),
        maxKnapSackProfit(cap, n-1, wt, val)
    );
}


int main() {

    int n,s;
    cin>>n>>s;
    int wt[n],value[n];
    for(int i=0; i<n; i++) cin>>wt[i];

    for(int i=0; i<n; i++) cin>>value[i];
    
    cout<<maxKnapSackProfit(s,n,wt,value);

	return 0;
}

// int main(){
//     int N,S;
//     cin>>N>>S;

//     int value[N],wt[N];

//     for(int i=0;i<N; i++){
//         cin>>wt[i];
//     }

//     for(int i=0;i<N; i++){
//         cin>>value[i];
//     }

//     // for(auto i:value) cout<<i<<" ";

//     cout<<knapSackProfit(S,wt,value, N);

//     return 0;
// }