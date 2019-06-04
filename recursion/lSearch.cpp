#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int lSearch(int arr[], int i, int n, int key){

    if(i>=n){
        return -1;
    }

    if(arr[i]==key) {
        return i;
    }

    return lSearch(arr, i+1,n,key);

}

int main() {
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    cout<<lSearch(arr,0,10,12)<<endl;
    return 0;
}