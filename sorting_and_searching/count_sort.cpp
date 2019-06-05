#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int arr[n],cp[1000001];
    for(int i=0 ; i<n; i++){
        cin>>arr[i];
    }

    memset(cp,0,sizeof(cp));
    for(int i=0; i<n; i++){
        // cout<<arr[i]<<" ";
        cp[arr[i]]+=1;
        // cout<<arr[i]<<" "<<cp[arr[i]]<<" ";
    }

    for(int i=0; i<1000001; i++){
        while(cp[i]!=0){
            cout<<i<<" ";
            cp[i]--;
        }
    }
	return 0;
}