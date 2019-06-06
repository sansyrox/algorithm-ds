#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void towerOfHanoi(int n, char src, char dest, char helper){
    // base case
    if(n==0) {
        return;
    }


    towerOfHanoi(n-1, src,helper,dest);
    cout<<"Moving ring "<<n<<" from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(n-1,helper,dest,src);

}

int main() {
    int n;
    cin>>n;
    towerOfHanoi(n,'A','B','C');
    return 0;
}