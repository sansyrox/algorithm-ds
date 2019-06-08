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

void insertAtTail(Node*&head, int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }

    Node*temp=head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = new Node(d);
    return;
}

void buildList(Node* &head){
    int d;
    cin>>d;
    while(d!=-1){
        insertAtTail(head,d);
        cin>>d;
    }
}

void printList(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head =head->next;
    }
}

istream& operator>>(istream &is, Node*&head) {
    buildList(head);
    return is;
}

ostream& operator<<(ostream &os, Node*head){
    printList(head);
    return os;
}

void reverse(Node* &head){
    Node *prev=NULL,*curr=head,*next=head;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr->next;
    }

    head = prev;

}

Node* reverseRecursion(Node* head){

    if(head==NULL){
        return NULL;
    }
    if(head->next == NULL){
        return head;
    }
    Node* nextHead = reverseRecursion(head->next);
    head->next->next = head;
    head->next = NULL;
    return nextHead; 

}

int main() {
    Node* head1=NULL;
    Node* head2=NULL;

    cin>>head1>>head2;
    cout<<head1<<endl<<head2;
    return 0;
}