#include<iostream>
using namespace std;

int maxSum(int arr[], int n){
    int cs[n];
    cs[0] = arr[0];
    for(int i=1; i<n; i++) {
        cs[i] = cs[i-1] + arr[i];
    }
    int left=-1,right=-1;

    int maxSum = -(int)1e9;
    for(int i=0; i<n; i++) {
        int currSum =0;
        for(int j=i; j<n; j++) {
             currSum = cs[j] - cs[i-1];
             if(currSum>maxSum) {
                 maxSum = currSum;
                left = i, right = j;
             }
        }
    }

    for(int i=left; i<=right; i++) {
        cout<<arr[i]<<",";
    }

    return maxSum;
}

int main() {
    int n; 
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<maxSum(arr,n);

    return 0;
}