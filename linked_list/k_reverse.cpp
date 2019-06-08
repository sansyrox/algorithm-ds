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

    Node* t = head;
    while(t->next!=NULL){
        t = t->next;
    }

    t->next = new Node(d);

}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* reverseKAtATime(Node* head, int k){
    if(head==NULL|| head->next==NULL){
        return head;
    }


    Node *prev=NULL,*curr=head,*next=head;

    while(k-- and curr!=NULL){
        next = 
    }


}

int main() {
    
    int n,k;
    cin>>n>>k;

    Node*head = NULL;
    while(n--){
        int t; cin>>t;
        insertAtTail(head,t);
    }

    reverseKAtATime(head, k);
    // print(head);

    return 0;
}