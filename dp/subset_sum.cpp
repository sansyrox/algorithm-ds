#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int sumHelper(string s){
    int sum=0;
    for(auto i:s) sum+= i-'0';

    return sum;

}

void subSetGen(string a, int i, int k,bool &toggler, string o=""){
    if(i==a.length()){
        // cout<<o<<endl;
        // add helper check
        toggler =sumHelper(o) == k ? true:false;
        return;
    }

    if(toggler==true){
        return;
    }

    subSetGen(a,i+1,k,toggler,o);
    subSetGen(a,i+1,k,toggler,o+a[i]);
    return;



}


int main() {
    
    return 0;
}