#include<iostream>
#include<queue> // isme priority que bhi implement ho rakhi hai
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#include<functional>

// Priority Queue
// pus ,pop ,empty top
// Comparators to reverse the comparision
// One such comparator is greater<int> present in 'functional' file

class Fruit {
    public:
        string name;
        int price;

        Fruit(string n, int p){
            name = n;
            price = p;
        }
};

class myCompare{

    public:
        bool operator() (Fruit a,Fruit b) {
            if(a.price == b.price){
                return a.name>b.name;
            }

            return a.price>b.price; // max heap ki tarah kaam karega , agar >b  => min heap
        }
};

int main() {
    // int a[] = {1,4,3,2,6,0,10,12};
    // int n = sizeof(a)/sizeof(int);

    // priority_queue<int> pmax; // max heap by default
    // priority_queue<int, vector<int>, myCompare > pq;  // min heap

    // for(int i=0; i<n; i++){
    //     pq.push(a[i]);
    // }


    // while(!pq.empty()){
    //     cout<<pq.top()<<" ";
    //     pq.pop();
    // }

    Fruit f1("Mango",180);
    Fruit f2("Apple",180);
    Fruit f3("Guava",60);
    Fruit f4("Banana",60);

    priority_queue<Fruit, vector<Fruit>, myCompare > pq;

    pq.push(f1);
    pq.push(f2);
    pq.push(f3);
    pq.push(f4);

    while(!pq.empty()){

        Fruit f =pq.top();
        pq.pop();
        cout<<f.name<<" "<<f.price<<endl;

    }

    // myCompare cmp;
    // int b=10;
    // cmp(b); //this  line will call the operator functor 
    // // object behaving as a function 

    return 0;
}