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

void insertAtTail(Node* &head, int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = new Node(d);
}

void buildList(Node* &head){
    int d;
    cin>>d;
    while(d!=-1){
        insertAtTail(head,d);
        cin>>d;
    }
}

Node* mid(Node* &head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    Node *slow=head, *fast=head->next;

    while(fast!=NULL and fast->next!=NULL){
        fast = fast->next->next;
        slow = slow->next;
    } 

    return slow;
}

Node* merge(Node* h1, Node* h2){
    if(h1==NULL) return h2;

    if(h2==NULL) return h1;

    Node*c;
    if(h1->data < h2->data){
        c = h1;
        c->next = merge(h1->next,h2);
    }
    else {
        c=h2;
        c->next = merge(h1,h2->next);
    }

    return c;
}


Node* mergeSort(Node* h1){
    if(h1==NULL or h1->next==NULL){
        return h1;
    }

    Node* midp = mid(h1);

    Node* a = h1;
    Node* b = midp->next;

    midp->next = NULL;

    a = mergeSort(a);
    b = mergeSort(b);

    Node*c = merge(a,b);

    return c;


}

void print(Node* head){

    while(head !=NULL){
        cout<<head->data<<"->";
        head= head->next;
    }

}

int main() {
    Node *h1=NULL,*h2=NULL;

    buildList(h1);
    h1 = mergeSort(h1);
    print(h1);

    return 0;
}