#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int n;cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    stack<int> s;

    int span[n];
    for(int i=0; i<n; i++) span[i]=0;
    s.push(0);
    for(int i=1; i<n; i++){
        // if(i==n-1) cout<<"Idahre";

        if(arr[i]>=arr[s.top()]){
            // cout<<"S is size is"<<s.size()<<" "<<span[i]<<endl;
            span[i]+=s.size();
            
            s.push(i);
        }
        else {
            
            while(!s.empty() and arr[i]<arr[s.top()]){
                s.pop();
            }
            s.push(i);
            span[i]=0;
        }
    }

    for(int i=0; i<n; i++){
        span[i]+=1;
    }

    for(int i=0; i<n; i++){
        cout<<span[i]<<" ";
    }
    cout<<"END";
    return 0;
}