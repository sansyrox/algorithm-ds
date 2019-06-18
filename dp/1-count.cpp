#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
//                                                                  &
int Count1(int arr[], int n, int k,int i, int curr_max, int &final_max){
    if(i==n){
        return 0;
    }

    // int ans =0;
    if(arr[i]==1){
        cout<<"Curr Max "<<curr_max<<endl;
        curr_max+=1; 
        cout<<"Curr Max "<<curr_max<<endl;
        cout<<"Final Max "<<final_max<<endl;
        final_max = max(final_max,curr_max);
        cout<<"Final Max "<<final_max<<endl;
        return 1 + Count1(arr,n,k,i+1,curr_max,final_max);
    }
    if(k>0 and arr[i]==1){
        int subans=INT_MIN;
        curr_max+=1;
        final_max = max(final_max,curr_max);
        subans = Count1(arr,n,k-1,i+1,curr_max, final_max);

        return 1 + max(
            subans,
            Count1(arr,n,k,i+1,0,final_max)
        );
    }


    return Count1(arr,n,k,i+1,0,final_max);
}

int main() {
    int n,k;
    cin>>n>>k;

    int arr[n];

    for(int i=0; i<n; i++) cin>>arr[i];
    int finalMax = 0;
    Count1(arr,n,k,0,0,finalMax);
    cout<<finalMax;
    return 0;
}