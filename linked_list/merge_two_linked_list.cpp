#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Node{
    public:
        int data;
        Node*next;
    
    Node(int d){
        data = d;
        next = NULL;
    }
};

Node* mergeLL(Node* a, Node*b){
    if(b==NULL){
        return a;
    }

    if(a==NULL){
        return b;
    }

    Node*c;
    if(a->data<b->data){
        c = a;
        c->next = mergeLL(a->next,b);
    }

    else {
        c = b;
        c->next = mergeLL(a,b->next);
    }

    return c;
}


void buildList(Node* &head){
    int d;
    cin>>d;
    while(d!=-1){
        insertAtTail(head,d);
        cin>>d;
    }
}

int main() {

    Node *h1=NULL, *h2=NULL;
    buildList(h1);
    buildList(h2);

    h1=llMerge(h1,h2);

    print(h1);


    return 0;
}