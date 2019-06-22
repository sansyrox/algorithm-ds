#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int helper(int s, int e, int t){
    
    if(t==0) return 0;
    // cout<<s<<" "<<e<<endl;
    int ans=s;
    
    while(s<=e){
        long long mid = (s+e)/2;
        
        if(mid*mid == t){
            ans = mid;
            return ans;
        }
        
        else if(mid*mid < (t)){
            cout<<mid<<endl;
            ans = mid;
            s = mid + 1;
        }
        
        else {
            e = mid - 1; 
        }
    }
    return ans;
    
}


// int Solution::sqrt(int A) {
//     // Do not write main() function.
//     // Do not read input, instead use the arguments to the function.
//     // Do not print the output, instead return values as specified
//     // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
//     return helper(0,A,A);
// }


int main() {
    cout<<helper(0,5,5);
    return 0;
}