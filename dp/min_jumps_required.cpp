// MINIMUM JUMPS REQUIRED
// You are provided an array of integers where each element represents the max number of steps you can take to move ahead.
// You need to check that how many minimum steps required to reach at the end of the array.

#include<iostream>
using namespace std;

int helper(int i,int n, int arr[]) {
    if(i>=n) {
        return 0;
    }

    

    

}

int main() {
    int t,n;
    cin>>t;

    while(t--) {
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        cout<<helper(0,n-1, arr)<<endl;


    }
    return 0;
}