#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
// implementation a circular queue

template<typename T>
class Queue{
    T*arr;
    int f;
    int r;
    int ms;
    int cs;

public:

    Queue(int ds=4){
        f=0;
        ms = ds;
        r = ms-1;
        arr = new T[ms];
        cs=0;
    }

    bool isFull(){
        return cs==ms;
    }

    bool isEmpty(){
        return cs==0;
    }

    void push(T data){
        if(!isFull()){
            r=(r+1)%ms;
            arr[r] = data;
            cs++;
        }
    }

    void pop(){
        if(!isEmpty()){
            f=(f+1)%ms;
            cs--;
        }
    }

    T getFront(){
        return arr[f];
    }

};



int main() {
    Queue<int> q(10);

    for(int i=0; i<=66; i++){
        q.push(i);
    }

    q.pop();
    q.push(8);

    while(!q.isEmpty()){
        cout<<q.getFront();
        q.pop();
    }
    

    return 0;
}