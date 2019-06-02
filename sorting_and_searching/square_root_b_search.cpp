#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int binSearch(int num, float precision) {

    int s=0, e =num;
    int ans,mid;
    while(s<=e){
        int mid = (s+e)/2;
        if(mid*mid==num){
            mid = ans;
            break;
        } else if(mid*mid < num) {
            s = mid+1;
            ans = mid;
        }
        else {
            e = mid - 1;
        }
    }

    for(float i =0.1; i<=precision; i+=0.1){
        ans+=0.1;
        if(ans*ans>num){
            ans-=0.1;
            break;
        }
    }

    return ans;

}

int main() {

    int num,precision;

    cout<<binSearch(15,0);

    return 0;
}