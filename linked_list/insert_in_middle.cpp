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
        this->data = d;
        this->next = NULL;
    }
};

int len(Node*head){
    int len=0;
    while(head!=NULL){
        head=head->next;
        len++;
    }

    return len;
}

void insertAtTail(Node* &head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    tail->next = new Node(data);
    return;
}

void insertAtHead(Node* &head, int data){
    if(head==NULL){
        head = new Node(data);
        return;
    }

    Node*temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertInMiddle(Node* &head, int data, int p) {
    
    if(head==NULL||p==0){
        insertAtHead(head, data);
    }
    else if(p>len(head)){
        insertAtTail(head,data);
    }
    else {
        int jump =1;
        Node*temp = head;
        while(jump<=p-1){
            temp=temp->next;
            jump += 1;
        }

        Node*n = new Node(data);
        n->next = temp->next;
        temp->next = n;
    }

}

int search(Node*head, int key){
    if(head==NULL){
        return -1;
    }
    int pos=0;
    while(head!=NULL){
        if(head->data==key){
            return pos;
        }
        head=head->next;
    }

    return -1;
}

int searchRecursion(Node*head, int key, int pos=0){
    if(head==NULL){
        return -1;
    }

    if(head->data==key){
        return pos;
    }

    return searchRecursion(head->next,key,pos+1);

}


void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
}


void deleteAtHead(Node*  &head){
    if(head==NULL){
        return;
    }

    Node*temp = head;
    head = head->next;
    delete temp;
    return;
}

void deleteAtTail(Node*&head){
    Node*prev;Node*temp;
    prev=NULL;
    temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
        prev=prev->next;
    }

    prev->next= NULL;
    delete temp;
    return;
}

void delteAtMiddle(Node* &head, int pos){
    if(head==NULL){
        return;
    }
    if(pos==0){
        deleteAtHead(head);
    }
    if(pos==len(head)-1){
        deleteAtTail(head);
    }

    Node*temp = head;
    while(pos>=1 and temp!=NULL){
        temp=temp->next;
        pos--;
    }

    Node*x = temp->next;
    temp->next = temp->next->next;
    delete x;

}

int main() {
    Node *head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,1);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertInMiddle(head,7,2);

    print(head);


    return 0;
}