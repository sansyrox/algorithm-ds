#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back


int main() {
    int x,y,z;
    cin>>x>>y>>z;

    int initial_vote = x - y;
    // int pos;

    // if(initial_vote>0) pos =1;
    // else if(initial_vote==0) pos =0;
    // else pos = -1;

    if(initial_vote>0 and z==0) cout<<"+";
    else if(initial_vote>0 and z>0) {
        if(initial_vote - z > 0) {
            cout<<"+";
        }else {
            cout<<"?";
        }
    }
    else if(initial_vote<0 and z==0) cout<<"-";
    else if(initial_vote<0 and z>0){
        if(initial_vote + z < 0){
            cout<<"-";
        }else {
            cout<<"?";
        }
    }
    else if(initial_vote==0 and z>0) {
        cout<<"?";
    }
    else if(initial_vote==0 and z==0) cout<<0;


    return 0;
}