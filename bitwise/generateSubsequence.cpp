#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void filterChar(string a, int i){
    int x=0;
    while(i){
        (i&1)?cout<<a[x]:cout<<"";
        i=i>>1 ;
        x++;
    }
    cout<<endl;
}

void generateSubsets(string a){ // subset == subsequence
    int n = a.length();
    int range = (1<<n) - 1;

    for(int i=0; i<=range; i++){
        filterChar(a,i);
    }

}

int main() {
    generateSubsets("abc");
    return 0;
}