#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

void reverseAStack(stack<int> s){
    stack<int> cpy;
    while(!s.empty()){
        int t = s.top();
        cpy.push(t);
        s.pop();
    }

    s = cpy;
}


void insertAtBottom(stack<int> &s, int t){
    if(s.empty()){
        s.push(t);
        return;
    }

    int x = s.top();
    s.pop();
    insertAtBottom(s,t);
    s.push(x);    

}

void reverseUsingRecursion(stack<int> s){
    if(s.empty()){
        return;
    }

    int t = s.top();
    s.pop();
    reverseUsingRecursion(s);
    insertAtBottom(s,t);

}

int main() {
    stack<int> s,t;
    for(int i=0; i<7; i++){
        s.push(i);
    }
    t=s;

    while(!t.empty()){
        cout<<t.top()<<endl;
        t.pop();
    }

    reverseAStack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    

    return 0;
}