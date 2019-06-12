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

Node* reverse(Node*&head){
    if(head==NULL and head->next==NULL){
        return head;
    }

    Node* chotaHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return chotaHead;
}

Node* reverseK(Node* head, int k){
    Node*prev = NULL, *curr=head,*last=head,*next=NULL;

    for(int i=1; i<=k-1; i++){
        last = last->next;
    }
    next = last->next;

    // first k ke liye pehle khud se karna


    // next k ke liye
    while(curr!=NULL){
        prev->next = NULL;
        last->next=NULL;

        re

    }


}

int main() {
    
    return 0;
}