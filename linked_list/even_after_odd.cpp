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

void insertAtTail2(Node* &head,Node* head2){
    if(head==NULL){
        head = head2;
        return;
    }

    Node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = head2;
    return;

}

void insertAtTail1(Node* &head,int d){
    if(head==NULL){
        head = new Node(d);
        return;
    }

    Node* temp = head;

    while(temp->next!=NULL){
        temp = temp->next;
    }

    temp->next = new Node(d);
    return;

}

void print(Node*head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main() {
    Node*head=NULL,*odd=NULL,*even=NULL;
    int n; cin>>n;
    while(n--){
        int k; cin>>k;
        if(k&1){
            // cout<<k<<endl;
            insertAtTail1(odd,k);

        }
        else{
            insertAtTail1(even,k);
        }
    }

    insertAtTail2(odd,even);

    print(odd);
    return 0;
}