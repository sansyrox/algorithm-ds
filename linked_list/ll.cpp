#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Node{

    public:
    int data;
    Node* next;

    Node(int d){
        data = d;
        next = NULL;
    }
};

// class LinkedList{
//     Node* head;
//     Node* tail;
// public:
//     LinkedList(){
//         head=NULL;
//         tail=NULL;
//     }
//     void insert(){

//     }

// };

void insertAtHead(Node* &head, int data){
    Node* n = new Node(data);
    n->next = head;
    head = n;
}

void print(Node*head){
    
    while(head!=NULL){
        cout<<head->data;
        head=head->next;
    }
}

void insertAfterPos(Node* &head,int pos, int data){
    Node*temp = head;

    while(pos-- and temp!=NULL){
        temp = temp->next;
    }

    Node* x = new Node(data);
    x->next = temp->next;
    temp->next=x;
}
int main() {
    Node* head=NULL;
    // int d;cin>>d;
    // head = new Node(d);
    // cout<<head->data;
    return 0;
}