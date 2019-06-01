// MAXIMUM CIRCULAR SUM
// You are provided n numbers (both +ve and -ve). Numbers are arranged in a circular form. You need to find the maximum sum of consecutive number.

// Input Format:
// First line contains integer t which is number of test case. For each test case, it contains an integer n which is the size of numbers and next line contains n space separated integers.

#include<iostream>
using namespace std;

int kadane(int arr[], int n){
    int cs= 0, ms=0;
    for(int i=0 ; i<n; i++) {
        if(cs+arr[i] > 0) {
            cs += arr[i];
            ms = max(ms,cs);
            // cout<<ms<<endl;
        } else {
            cs = 0;
        }
    }

    if(ms==0) {
        return *max_element(arr, arr+n);
    }
    return ms;
}


int maxSum(int arr[], int n) {
    int can1 = kadane(arr,n);

    int sum=0;
    for(int i=0; i<n; i++) {
        sum+=arr[i];
        arr[i]*=-1;
    }

    sum = sum + kadane(arr,n);


    return (sum>can1)? sum:can1;

}

int main() {

    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) cin>>arr[i];

        cout<<maxSum(arr,n)<<endl;
    }

    return 0;
}