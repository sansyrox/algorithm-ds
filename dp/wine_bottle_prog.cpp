#include<iostream>
using namespace std;

int mem[100][100];

int maxProfit(int *arr, int be, int end, int year=1){
    if(be>end) {
        return 0;
    }

    if(mem[be][end] != -1) return mem[be][end];

    int q1 = year*arr[be] + maxProfit(arr, be+1, end, year+1);
    int q2 = year*arr[end] + maxProfit(arr, be, end-1, year+1);

    mem[be][end] = max(q1,q2);

    return mem[be][end];

}
int maxProfit(int arr[], int n){
    int dp[100][100] = {};
    int year = n;

    for (int i = 0; i < n; i++) {
        dp[i][i] = year*arr[i]
    }
    

    for (int len= 2; len<=n; len++) {
        int srt = 0;
        int end = n- len -1;
        while (srt <= end) {
            int endwindow = srt + len - 1;
            dp[srt][endwindow] = max(
                arr[srt]*year + dp[srt+1][endwindow],
                arr[endwindow]*year + dp[srt][endwindow -1]
            )
            ++srt;
        } 
        --year;
    }
    
    return dp[0][n-1];

}


int main(){

    int arr[] = {4,3,1,2,5};
    memset(mem, -1, sizeof(mem));
    cout<<maxProfit(arr,0,4,1)<<endl;
    return 0;
}