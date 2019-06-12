#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int areaUnderHistoGram(int a[], int n){

    // correct approach but now the array will ahev zero as first and last index

    int area[n];
    memset(area,0,sizeof(area));
    stack<int> helper;
    helper.push(0);

    for(int i=1; i<n; i++){
        if(a[i]>=a[helper.top()]){
            helper.push(i);
        }
        else{
            while(a[i]<a[helper.top()]){
                int t = helper.top();
                helper.pop();
                if(helper.size()!=0)

                    area[t] = a[t]*(i-helper.top()-1);
                    // cou<<t<<endl;
                else
                    area[t] = a[t]*i;
                
            }
        }
    }

    return *max_element(area,area+n);

}

int main() {
    int n;
    cin>>n;
    int arr[n+2];
    arr[0] = 0;
    for(int i=1; i<n+1; i++){
        // cout<<i<<endl;
        cin>>arr[i];
    }
    arr[n+1] = 0;
    cout<<endl;

    // for(int i=0; i<n+2; i++) cout<<arr[i]<<" ";
    cout<<areaUnderHistoGram(arr,n+2);

    
    return 0;
}