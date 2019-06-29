// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define mp make_pair
// #define pb push_back

// const int mno = 10000003;

// bool isValid(ll arr[], ll n, ll k, ll ans){
//     ll count =1; // count of painters
//     ll sum=0;
//     for(int i=0; i<n; i++){
//         sum+=arr[i];
//         if(sum>ans){
//             count++;
//             sum=arr[i];
//         }
        
//     }

//     if(count>k){
//         return false;
//     }
//     return true;

// }

// ll minTime(ll arr[], ll n, ll k) {
//     ll s=arr[n-1];
//     ll e=0;
//     for(ll i=0;i<n; i++){
//         e+=arr[i];
//     }

//     ll ans;
//     while(s<=e){
//         ll mid=(s+e)/2;
//         if(isValid(arr, n, k, mid)){
//             e = mid-1;
//             ans = mid;
//         }
//         else {
//             s = mid + 1;
//         }
//     }

//     return ans;
// }

// int main() {
//     ll n,k,t;
//     cin>>n>>k>>t;
//     ll arr[n];
    
//     for(ll i=0; i<n; i++) {
//         cin>>arr[i];
//     }

//     sort(arr,arr+n);
//     cout<<(minTime(arr,n,k)%mno * t%mno)%mno;

//     return 0;
// }


/*
You have to paint N boards of length {A0, A1, A2, A3 … AN-1}. There are K painters available and you are also given how much time a painter takes to paint 1 unit of board. You have to get this job done as soon as possible under the constraints that any painter will only paint contiguous sections of board.

2 painters cannot share a board to paint. That is to say, a board
cannot be painted partially by one painter, and partially by another.
A painter will only paint contiguous boards. Which means a
configuration where painter 1 paints board 1 and 3 but not 2 is
invalid.
Return the ans % 10000003

Input :
K : Number of painters
T : Time taken by painter to paint 1 unit of board
L : A List which will represent length of each board

Output:
     return minimum time to paint all boards % 10000003
Example

Input : 
  K : 2
  T : 5
  L : [1, 10]
Output : 50
*/

bool isPossible(int A, int B, vector<int> &C,long long int X){
    int n=C.size();
   long long int t=X;
    int i=0,cnt=1;
    while(i<n){
        if(cnt>A)
         return false;
        if(C[i]>t){
            cnt++;
            t=X;
        }
        else{
            t=t-C[i];
            i++;
        }
    }
    return true;
}

int Solution::paint(int A, int B, vector<int> &C) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=C.size();
    long long int sum=0;
    for(int i=0;i<n;i++)
     sum=sum%10000003+C[i]%10000003;
    long long int low=0,high=sum*B;
    long long int ans=high%10000003;
    while(low<=high){
        //cout<<low<<" "<<high<<" "<<ans<<endl;
        long long int mid=low+(high-low)/2;
        if(isPossible(A,B,C,mid/B)){
           // cout<<"Hi\n";
            ans=mid%10000003;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans%10000003;
}



bool isValid(vector<int> &arr, int k, long long ans){
    int count = 1;
    int sum = 0;
    
    for(auto i:arr){
        sum+=i;
        if(sum> ans){
            count++;
            if(count > k){
                return false;
            }
            sum=i;
        }
    }
    
    return count<=k;
    
}

int Solution::paint(int A, int B, vector<int> &C) {
    if(A==0 and !C.empty()){
        return INT_MAX;
    }
    
    if(A==0 and C.empty()){
        return 0;
    }
    
    
    
    sort(C.begin(), C.end());
    long long s = C[C.size()-1];
    long long e=0;
    for(auto i:C) e+=i;
    int ans = 0;
    
    while(s<=e){
        long long mid = (s+e)/2;
        // cout<<mid<<endl;
        if(isValid(C,A,mid)){
            ans = mid;
            e = mid - 1;
            // cout<<ans<<endl;
        }
        else {
            s = mid+1;
        }
    }
    
    
    
    return (((ans%10000003)*(B%10000003))%10000003);;
}

bool isValid(vector<int> &arr, int k, long long ans){
    int count = 1;
    int sum = 0;
    
    
    for(auto i:arr){
        if(sum + i > ans){
            count++;
            sum=0;
        }
        
        sum+=i;
    }
    
    return count<=k;
    
}

int Solution::paint(int A, int B, vector<int> &C) {
    if(A==0 and !C.empty()){
        return INT_MAX;
    }
    
    if(A==0 and C.empty()){
        return 0;
    }
    
    
    
    sort(C.begin(), C.end());
    long long s = C[C.size()-1];
    long long e=0;
    for(auto i:C) e+=i;
    int ans = 0;
    
    while(s<=e){
        long long mid = (s+e)/2;
        cout<<mid<<endl;
        if(isValid(C,A,mid)){
            ans = (((mid%10000003)*(B%10000003))%10000003);
            e = mid - 1;
            
            // cout<<ans<<endl;
        }
        else {
            s = mid+1;
        }
    }
    
    return (((ans%10000003)*(B%10000003))%10000003);;
}
