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

    Node* temp=head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = new Node(d);
    return;
}

Node* reverse(Node* head){
    if(head==NULL or head->next==NULL){
        return head;
    }

    Node* prev=NULL, *curr=head, *next=head;
    
    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;

    return head;
}

bool isPalindrome(Node* h1, Node* h2){
    while(h1!=NULL and h2!=NULL){
        if(h1->data!=h2->data){
            return false;
        }
        h1=h1->next;
        h2=h2->next;
    }
    
    return true;

}

int main() {
    int N; cin>>N;
    Node* head = NULL;
    while(N--){
        int d; cin>>d;
        insertAtTail(head,d);
    }

    Node* head2 = reverse(head);

    isPalindrome(head,head2) == true ? cout<<"True":cout<<"False";

    return 0;
}