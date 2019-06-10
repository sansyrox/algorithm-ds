#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

template<typename T, typename U>
class Stack{
    vector<T> s;
    vector<U> v2;
public:
    void push(T d){
        s.pb(d);
    }

    void pop(){
        s.pop_back();
    }

    T top(){
        return s.at(s.size()-1);
    }

    bool isEmpty(){
        return s.size()==0;
    }

};


int main() {
    Stack<int, char> S;

    S.push(4);
    S.push(5);
    S.push(6);
    S.push(7);

    while(!S.isEmpty()){
        cout<<S.top()<<endl;
        S.pop();
    }

    return 0;
}