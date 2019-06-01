// RAIN WATER HARVESTING
// Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

// Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

// Explanation for the Sample input Testcase:
// Elevation Map

// So the total units of water she can save is 5 units

// Input Format:
// First line contains an integer n. Second line contains n space separated integers representing the elevation map


#include<iostream>
using namespace std;

int rainWaterHarvesting(int arr[], int n) {
    int left[n],right[n];
    left[0]=0;
    right[n-1] = n-1;

    for(int i=1; i<n; i++) {
        if(arr[i]<arr[left[i-1]]) {
            left[i] = left[i-1];
        } 
        else left[i] = i;
    }

    for(int i=n-2; i>=0; i--) {
        if(arr[i]<arr[right[i+1]]) {
            right[i] = right[i+1];
        }
        else right[i] = i;
    }

    int sum =0;

    for(int i=0; i<n; i++) {
        int minValue = min(arr[left[i]], arr[right[i]]);

        if(minValue - arr[i] > 0) sum += minValue - arr[i];

    }

    return sum;

}


int main() {
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    cout<<rainWaterHarvesting(arr ,n);



    return 0;
}