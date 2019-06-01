// Finding maximum sum in a subArray using kadane's algorithm


#include<iostream>
using namespace std;

int maxSum(int arr[], int n){
    int cs=0, ms=0;

    for(int i=0; i<n; i++) {
        if(cs + arr[i]<0) {
            cs = 0;
        }
        cs += arr[i];
        ms = max(cs,ms);
    }

    if(ms==0) {
        ms = *max_element(arr,arr+n);
    }

    return ms;

}


int main() {
    int n;
    cin>>n;
    int arr[n];

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<maxSum(arr, n);

    return 0;
}