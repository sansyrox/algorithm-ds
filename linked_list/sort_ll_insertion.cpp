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

void insertAtSorted(Node *&head, int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }

    Node* temp = head;
    Node*prev = NULL;
    while(temp!=NULL and temp->next!=NULL){
        
        if(temp->next->data <= d and temp->data >= d){
            Node*x = new Node(d);
            x->next = temp->next;
            temp->next = x;
            temp = temp->next->next;
            
        }else{
            
            // temp = temp->next;
        }
        
    }

    if(temp->next==NULL and temp!=NULL and d>=temp->data){
        temp->next = new Node(d);
    }

    return;
}



void insertionSort(Node* &head){
    if(head==NULL or head->next==NULL){
        return;
    }

    Node *sorted=NULL;
    Node *unsorted = head;

    while(unsorted!=NULL){
        insertAtSorted(sorted, unsorted->data);
        unsorted = unsorted->next;
        cout<<sorted->data<<endl;
    }

    head = sorted;
}

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

int main() {
    Node*head=NULL;
    int n; cin>>n;
    while(n--){
        int d; cin>>d;
        insertAtTail(head,d);
    }

    print(head);cout<<endl;
    insertionSort(head);

    print(head);
    return 0;
}