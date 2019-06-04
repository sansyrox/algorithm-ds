#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int N=1000000;
int p[1000001] = {0};

void primeSieve(int n){

    p[0]=p[1]=0;
    p[2] = 1;

    // Let us mark all odd numbers as prime
    for(int i=3; i<=n; i+=2){
        p[i] = 1;
    }

    // Sieve logic to mark non prime nmbers as zero
    //1. Optimization: Iterate only over odd numbers
    for(int i=3; i<=n; i+=2){
        if(p[i]) {
            // Mark all the multiples of that number as not prime
            // 
            for(int j=i*i; j<=n; j+=2*i){
                p[j]=0;
            }
        }
    }

}


int main() {
    int n;
    cin>>n;
    primeSieve(n);

    for(int i=0; i<=n; i++){
        if(p[i]) cout<<i<<" ";
    }
    return 0;
}