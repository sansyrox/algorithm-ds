#include<iostream>
#include<queue> // isme priority que bhi implement ho rakhi hai
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#include<functional>

// Priority Queue
//pus ,pop ,empty top
// Comparators to reverse the comparision
// One such comparator is greater<int> present in 'fucntional' file

int main() {
    int a[] = {1,4,3,2,6,0,10,12};
    int n = sizeof(a)/sizeof(int);

    priority_queue<int> pmax; // max heap by default
    priority_queue<int, vector<int>, greater<int> > pq;  // min heap

    for(int i=0; i<n; i++){
        pq.push(a[i]);
    }


    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    return 0;
}