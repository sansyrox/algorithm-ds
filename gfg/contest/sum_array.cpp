#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--){
	    int n;cin>>n;
	    int arr[n];
	    for(int i=0 ; i<n; i++) cin>>arr[i];
	    
	   // if(n==1){
	   //     cout<<arr[0]<<endl;
	   //     continue;
	   // }
	    

	    
	    int sum[n];
	    sum[0] = arr[0];
        sum[1]=max(sum[0],arr[1]);
	    
	    for(int i=2; i<n; i++){
	        sum[i] = max(arr[i],max(sum[i-1],arr[i]+sum[i-2]));
	    }
	    
	   // cout<<*max_element(sum,sum+n)<<endl;
	    for(auto i:sum){
	        cout<<i<<" ";
	    }
	    cout<<endl;
	    
	}
	return 0;
}