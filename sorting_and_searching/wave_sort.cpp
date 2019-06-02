#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int a[10] = {2,1,3,5,4,6,7,8,10,9};
    if(a[0]>a[1]) {
        swap(a[0],a[1]);
    }
    for(int i=2; i<10; i+=2){
        if(a[i]>a[i-1]){
            swap(a[i],a[i-1]);
        }
        if(a[i]>a[i+1]){
            swap(a[i],a[i+1]);
        }
    }

    for(auto i:a) cout<<i<<" ";
    return 0;
}