#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Stack {
    int len;
    int s,e;
    int *arr;
public:
    Stack(int len=5){
        this->len = len;
        // s=0;
        e=0;
        arr = new int[len];
    }

    void insert(int x){
        if(e==len-1){
            len = 2*len;
            int *newArr = new int[len];
            for(int i=0; i<=e; i++){
                newArr[i] = arr[i];
            }

            delete [] arr;
            arr = newArr;
        }

        arr[e] = x;
        e++;
    }

    void pop(){
        if(e==0){
            return;
        }
        e--;
    }

    void print_stack(){
        if(e==0){
            cout<<-1;
            return;
        }
        for(int i=e; i>=0; i--){
            cout<<arr[e]<<" ";
        }
    }

    ~Stack(){
        delete []arr;
    }
};

int main() {
    int t; cin>>t;
    while(t--){
        Stack S;
        int q; cin>>q;
        while(q--){
            int a,b;
            cin>>a;
            if(a==2){
                // pop_back

                // print idhar
                continue;
            }
            cin>>b;
            // push b
            // print idhar
        }
    }
    return 0;
}