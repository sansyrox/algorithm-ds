// wts ka vector, max capacity


#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

int ans(int w, vector<int> &wts, int i=0) {
    if(w==0 || i==wts.size()) {
        return 0;
    }


    int an  = 0;
    an += ans(w,wts, i+1);

    if(wts[i]<=w){
        an+= wts[i] + ans(w-wts[i],wts,i+1);
    }


    return an;
}



int main() {
    
    return 0;
}