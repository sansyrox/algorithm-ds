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
};

Node* middle(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast!=NULL and fast->next!=NULL){
        fast= fast->next->next;
        slow = slow->next;
    }

    return slow;

}

Node* kThNodeFromLast(Node* head, int k){
    Node* fast = head,*slow=head;
    while(k-- and fast!=NULL){
        fast = fast->next;
    }

    while(fast->next!=NULL){
        fast = fast->next;
        slow=slow->next;
    }

    return slow;
}

int main() {
    
    return 0;
}