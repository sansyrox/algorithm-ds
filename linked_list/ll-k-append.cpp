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
        data=d;
        next=NULL;
    }
};

void inserAtTail(Node* &head, int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = new Node(d);
    return;


}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

void inserAtTail2(Node* &head, Node* head2){
    if(head==NULL){
        head = head2;
        return;
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next = head2;
    // print(head);
    // cout<<endl;

    return;


}



int main() {
    int n,k;
    cin>>n;
    int x = n;

    Node* head = NULL;

    while(n--){
        int d; cin>>d;
        inserAtTail(head, d);
    }

    cin>>k;
    cout<<k<<endl;
    if(k<x) {
        // cout<<"Idahr\n";
        int no = x-k-1;
        Node* t = head;
        while(no--){
            // cout<<"Idahr\n";
            t =t->next;
        }
        Node* newHead = t->next;
        t->next=NULL;
        inserAtTail2(newHead,head);
        head = newHead;
    }
    
   
    print(head);
    

    return 0;
}