#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Node {
    public:
    int data;
    Node* next;

    // Constructor
    Node(int d){
        data = d;
    }
};

void printList(Node* head){
    Node* temp = head;
    while(temp->next!=head){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<temp->data<<" END";
}

Node* getNode(Node* head,int data){
    Node* temp = head;

    while(temp->next!=head){
        if(temp->data==data) return temp;
        temp = temp->next;
    }

    if (temp->data==data) return temp;

    return NULL;

}


void deleteNode(Node* &head,int d){
    Node* node = getNode(head,d);
    if(node==NULL) return;

    Node* temp = head;

    while(temp->next != node){
        temp=temp->next;
    }

    // Node* curr = temp;
    temp->data = temp->next->data;
    temp->next = temp->next->next;
    return;

}

void push(Node *&head, int data){
    Node* ptr1 = new Node(data);
    Node *temp = head;
    ptr1->next = head;

    if(head!=NULL){
        while(temp->next!=head){
            temp=temp->next;
        }
        temp->next = ptr1;
    }
    else {
        ptr1->next = ptr1;
    }

    head = ptr1;

}


int main() {
    
    return 0;
}