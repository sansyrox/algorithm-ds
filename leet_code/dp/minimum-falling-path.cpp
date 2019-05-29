// Given a square array of integers A, we want the minimum sum of a falling path through A.

// A falling path starts at any element in the first row, and chooses one element from each row.  The next row's choice must be in a column that is different from the previous row's column by at most one.




class Solution {
public:
    int dp[1001][1001];
    
    int helperFunction(vector<vector<int> > &A, int i, int j){
        
        if(i>=A[0].size() or j>=A[0].size()){
            return 0;
        }
        
        if(dp[i][j]!=0){
            return dp[i][j];
        }
        if (i==A[0].size()-1){
            return  dp[i][j]=A[i][j];
        }
        
        if(j==A[0].size()-1){
            return dp[i][j]=A[i][j] + min(
                helperFunction(A,i+1,j),
                helperFunction(A,i+1,j-1)
                );
        }
        
        if(j==0){
          return dp[i][j]= A[i][j] + min(
            helperFunction(A, i+1, j+1),
            helperFunction(A,i+1,j)
            );  
        }
        
        return dp[i][j]=A[i][j] + min(
             helperFunction(A, i+1, j-1), 
            min(helperFunction(A, i+1, j+1),helperFunction(A,i+1,j))
        );
        
        
    }
    
    int minFallingPathSum(vector<vector<int> >& A ) {
        int sum = (int)1e7;
        for(int j=0; j<A[0].size();j++){
            // cout<<"J ki value idhar hai bc "<<j<<endl;
            memset(dp, 0, sizeof(dp));
            int ans = helperFunction(A,0,j);
            // cout<<"ans ye hai "<<ans<<endl;
            sum = min(sum, ans);
        }
        
        return sum;
    }
};