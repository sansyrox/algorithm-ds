#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool comp(int a,int b){
    return a>b;
}


int ans123(int n){
    int arr[n];
    float sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(ceil(sum/n)!=floor(sum/n)){
        return -1;
    }
    int avg = sum/n;
    sort(arr,arr+n,comp);
    int carr=0;
    int count=0;
    for(int i=0; i<n; i++){
        if(arr[i]<avg){
            if(count==0){
                return -1;
            }
            carr-=(avg-arr[i]);
            arr[i] = avg;
        }
        else if(arr[i]>avg){
            carr+=(arr[i]-avg);
            count+=(arr[i]-avg);
        }
    }

    return count;
}

int main() {
    int t; cin>>t;
    while(t!=-1){
        cout<<ans123(t)<<endl;

        cin>>t;
    }
    return 0;
}