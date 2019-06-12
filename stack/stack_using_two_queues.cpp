#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Stack{
    queue<int> q1,q2;
    // insert in q1, pop from q2

    public:

        void push(int d){
            q1.push(d);
        }

        bool isEmpty(){
            return q1.size()==0;
        }

        void pop(){
            int n = q2.size() -1;

            while(n--){
                q2.push(q1.front());
                q1.pop();
            }

            q1.pop();
            swap(q1,q2);
        }

        int top(){
            q1.back();
        }




};


int main() {
    
    return 0;
}