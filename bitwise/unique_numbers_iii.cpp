#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int returnUniqueNumber(int arr[], int n){
    int count[64]={0};

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    for(int i=0;i<n; i++){
        int j=0;
        while(arr[i]>0){
            int t = arr[i]&1;
            count[j++]+=t;
            arr[i]=arr[i]>>1;
        }
    }

    for(int i=0; i<64; i++){
        count[i]%=3;
    }

    int sum=0;
    for(int i=0; i<64; i++){
        sum+=count[i]<<i;
    }


    // cout<<endl;

    // for(int i=0; i<n; i++){
    //     cout<<arr[i]<<" ";
    // }
    // cout<<endl;

    return sum;

}

int main() {
    int n; cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<returnUniqueNumber(arr,n);


    return 0;
}