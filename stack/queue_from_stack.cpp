#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Queue{
    stack<int> s1,s2; // s1 stays empty
    public:
        void insertAtBottom(int d){

            while(s2.size()!=0){
                s1.push(s2.top());
                s2.pop();
            }

            s2.push(d);

            while(s1.size()!=0){
                s2.push(s1.top());
                s1.pop();
            }

        }

        void push(int t){
            insertAtBottom(t);
        }

        void pop(){
            if(s2.size()!=0){
                s2.pop();
            }
        }

        int front(){
            return s2.top();
        }


        bool isEmpty(){
            return s2.size()==0;
        }

};

int main() {
    Queue q;

    int a;cin>>a;
    
    for(int i=0; i<=a-1; i++){
        q.push(i);
    }
    // cout<<"idahe";
    while(!q.isEmpty()){
        cout<<q.front()<<" ";
        q.pop();
    }


    return 0;
}