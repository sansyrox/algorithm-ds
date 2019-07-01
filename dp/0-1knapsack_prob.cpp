#include <bits/stdc++.h>
using namespace std;

// int dp[1001][1001];

int maxKnapSack(int val[], int wt[], int n, int i, int w){

    // if(dp[i][w]!=-1){
    //     return dp[i][w];
    // }
    
    // if(wt[i-1]>w){
    //     return maxKnapSack(val,wt,n,i-1,w);
    // }
    
    // if(wt[i-1]==0){
    //     return dp[i][w]=maxKnapSack(val,wt,n,i-1,w);
    // }
    int dp[n+1][w+1];

    

    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
                continue;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=w; j++){
            

            if(wt[i-1]<=j and i>=1){
                dp[i][j] = max(
                    dp[i-1][j],
                    val[i-1] + dp[i-1][j-wt[i-1]]
                );
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    // return dp[i][w]=max(
    //         maxKnapSack(val,wt,n,i-1,w),
    //         val[i-1] + maxKnapSack(val,wt,n,i-1,w-wt[i-1])
    //     );
    // for(int i=0; i<=n; i++){
    //     for(int j=0; j<=w; j++){
    //         cout<<dp[i][j]<<" ";
    //     }cout<<endl;
    // }

    return dp[n][w];
    
}

int main() {
	//code
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t; cin>>t;
	while(t--){
	    int w,n; 
	    cin>>n;
	    cin>>w;
	    int val[n], wt[n];
	    for(int i=0; i<n; i++){
	        cin>>val[i];
	    }
	    for(int i=0; i<n; i++){
	        cin>>wt[i];
	    }
	    
	    // memset(dp,-1,sizeof(dp));
	    cout<<maxKnapSack(val, wt,n, n, w)<<endl;
	}
	return 0;
}