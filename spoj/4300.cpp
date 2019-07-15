#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int t=1;
    while(t--){
        int n;
        cin>>n;
        // number of squares
        int ans = sqrt(n);

        // number of rectangles

        for(int i=1; i<=sqrt(n); i++){
            for(int j=i+1; i*j<=n; j++){
                ans++;
            }
        }

        cout<<ans<<endl;
        }
    return 0;
}