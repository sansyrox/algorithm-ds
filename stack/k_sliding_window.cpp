#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void maxElementInAWindow(int arr[],int n, int k){

    int i=0;
    deque<int> q(100);
    for(int i=0; i<k; i++){
        while(!q.empty() and arr[i]>=arr[q.front()]){
            q.pop_back();
        }
        q.pb(i);
    }

    i=k;

    for(;i<n; i++){
        cout<<q.front()<<" ";
        while(!q.empty() and q.front()>=i-k){
            q.pop_front();
        }
        while(!q.empty() and arr[i]>=arr[q.front()]){
            q.pop_back();
        }
        q.pb(i);
    }

    return;
}


int main() {
    int n;
    int arr[10000000];
    int k;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>k;

    maxElementInAWindow(arr,n,k);
    return 0;
}