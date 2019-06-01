#include<iostream>
using namespace std;

int myCompare(int a, int b) {
    if(a>b) {
        return 1;
    } else return 0;
}

int main() {
    int a[10] = {1,2,3,4,0,21,1,2};

    sort(a,a+10,myCompare);

    for(auto i:a) cout<<i<<" ";

    return 0;
}