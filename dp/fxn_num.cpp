// #include <bits/stdc++.h>
// using namespace std;

// //x+1
// int dp[1001];
// int fx(int x){
//     // cout<<"Idhar \n";
//     if(x<0){
//         return 0;
//     }
//     if(x==0 or x==1){
//         return dp[x]=1;
//     }
    
//     if(dp[x]!=-1) return dp[x];
    
//     int i = fx(x-1);
//     return dp[x]=i-(x-1) ;
// }

// int main() {
// 	//code
// 	int t;cin>>t;
// 	while(t--){
// 	    memset(dp,-1,sizeof(dp));
// 	    int n; cin>>n;
// 	    cout<<fx(n)<<endl;
// 	}
// 	return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int outputK(int n){
    if(n<9){
        return n;
    }
    vector<int> a;
    cout<<"idhar"<<endl;
        for(int i=2; i<=9; i++){
            if(n%i==0){
                a.push_back(i);
                n=n/i;
            }
        }

    cout<<"idhar"<<endl;
    if(n>=10){
        return -1;
    }
    
    string i="";
    
    for(auto j:a) i+=j;
    
    sort(i.begin(),i.end());
    
    return stoi(i);
}

int main() {
	//code
	int t;cin>>t;
	while(t--){
	    int n;cin>>n;
	    cout<<outputK(n)<<endl;
	}
	
	return 0;
}