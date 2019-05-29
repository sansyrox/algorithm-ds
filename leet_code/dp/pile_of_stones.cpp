// 877. Stone Game
// Medium

// 287

// 528

// Alex and Lee play a game with piles of stones.  There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones.  The total number of stones is odd, so there are no ties.

// Alex and Lee take turns, with Alex starting first.  Each turn, a player takes the entire pile of stones from either the beginning or the end of the row.  This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alex and Lee play optimally, return True if and only if Alex wins the game.


// #include<bitset/stdc++.h>
#include<vector>
using namespace std;

class Solution {
public:
    int dp[1001][1001];
    int helper(vector<int> &piles, int i, int j) {
        if(i>j){
            return 0;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j] = max(
            piles[i] + max(
                helper(piles, i+2,j),
                helper(piles, i+1,j-1)
            ),

            piles[j] + max(
                helper(piles, i,j-1),
                helper(piles, i+1,j-1)
            )
        );
    }
    
    int sum(vector<int>& a){
        int i=0;
        for(auto j:a) i+=j;

        return i;
    }

    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int alex = helper(piles,0, piles.size()-1);


        int other = sum(piles) - alex;

        return (alex>other)? true: false;
    }
};

