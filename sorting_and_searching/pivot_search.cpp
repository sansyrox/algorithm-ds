//search for the largest  number
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

bool unSorted(int arr[], int s, int e) {
    bool unSorted = false;

    for(int i=s; i<e; i++){
        if(arr[i])
    }

}

int pivotFinding(int arr[], int s, int e){
    while(s<=e){
        int mid = (s+e)/2;
        if(mid<e and  arr[mid]>arr[mid-1]){
            return mid;
        }

        else if(mid>s and arr[mid]<arr[mid-1]){
            return mid;
        }

        else if(arr[s]>=arr[mid]) {// right unsorted
                e = mid -1;
            }
        else { // left unsorted
                e = mid -1;
            }

    }
}

int main() {



    return 0;
}