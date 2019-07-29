#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void multiply(vector<int>&a, int x, int &size){

    int carry=0;
    int i;
    for(i=0; i<size; i++){
        int prod = a[i]*x + carry;
        a[i] = prod%10;
        carry=(prod/10);
    }

    while (carry) 
    { 
        a[size] = carry%10; 
        carry = carry/10; 
        size++; 
    } 

}

void factorial(int n){
    vector<int> a(1000000,1);
    int size=1;

    for(int i=2; i<=n; i++){
        multiply(a,i,size);
        // size++;
    }

    for(int i=size-1; i>=0; i--) cout<<a[i];
    cout<<endl;
    // return 0;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;
        // cout<<n<<endl;
        factorial(n);
        // double ans = 1;
        // for(int i=1; i<=n; i++) ans*=i;
        // cout<<ans<<endl;
    }
    return 0;
}