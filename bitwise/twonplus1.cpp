#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int getFirstSetBit(int n){
    int index = -1;

    while(n){
        index++;
        if((n&1) !=0){
            return index;
        }
        n=n>>1;
    }

    return index;
}

int getIthBit(int n, int i){
    // cout<<"I ki value"<<i<<endl;
    return (n & (1<<i)) != 0?1:0;
}

pair<int,int> returnNo(int arr[], int n){
    int xor_sum=arr[0];
    for(int i=1; i<n; i++){
        xor_sum=xor_sum^arr[i];
    }
    // cout<<"XOR SUM "<<xor_sum<<endl;
    int set_index = getFirstSetBit(xor_sum);
    // cout<<"SET INDEX"<<set_index<<endl;
    // vector<int> set_at_index,unset_at_index;

    
    // for(int i=0; i<n; i++){
    //     if(getIthBit(arr[i],set_index) !=0) {
    //         // cout<<"Get"<<i<<" bit "<<getIthBit(i,set_index)<<arr[i]<<endl;
    //         set_at_index.pb(arr[i]);
    //     }
    //     unset_at_index.pb(arr[i]);
    // }

    int ans = 0;
    int mask= (1<<set_index);
    for(int i=0; i<n; i++){
        if((mask&arr[i])!=0){
            ans ^= arr[i];
        }
    }

    int secondNo = xor_sum^ans;
    int x[2];
    x[0] = ans;
    x[1] = secondNo;


    return mp(x[0],x[1]);


}

int main() {
    int arr[] = {1,1,2,2,3,3,4,8,5,5,6,6,7,7};
    int n=sizeof(arr)/sizeof(int);

    pair<int,int> x=returnNo(arr,n);
    cout<<x.first<<" "<<x.second<<endl;

    return 0;
}