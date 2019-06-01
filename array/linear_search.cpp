#include<iostream>
using namespace std;

int lSearch(int arr[], int n, int key) {

    for(int i=0; i<n; i++) {
        if(arr[i]==key){
            return i;
        }
    }

    return -1;
}

int main() {

    int arr[10] = {1,2,3,4,5,6,7,8,9,10};

    cout<<lSearch(arr,10,8);

    return 0;
}