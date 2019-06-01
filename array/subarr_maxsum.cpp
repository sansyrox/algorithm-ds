#include<iostream>
using namespace std;

int main(){
int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    int maxSum = -(int)1e7;
    int left = -1,right = -1;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            int sum = 0;
            for(int k=i; k<=j; k++) {
                sum+=arr[k];
            }
            if(sum > maxSum) {
                left = i;
                right = j;
                maxSum = sum;
            }
        }
        
    }

    // print the sub array
    for(int k=left; k<=right; k++) {
        cout<<arr[k]<<",";
    }
    cout<<endl;
    cout<<maxSum<<endl;


return 0;
}
