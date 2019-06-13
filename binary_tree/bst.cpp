#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int d){
        data = d;
        left=right=NULL; 
    }
};

Node* insertBST(Node* root, int d){

    if(root==NULL){
        root = new Node(d);
        return root;
    }

    if(d<root->data){
        root->left = insertBST(root->left,d);
    }
    else {
        root->right = insertBST(root->right,d);
    }

    return root;



}

bool search(Node* root, int data){
    if(root==NULL) {
        return false;
    }

    if(root->data == data){
        return true;
    }

    if(data<root->data){
        return search(root->left,data);
    }
    else {
        return search(root->right,data);
    }
}

bool isBst(Node*root, int minV=INT_MIN, int maxV=INT_MAX){
    if(root==NULL){
        return true;
    }

    if((root->data>=minV and root->data<=maxV) and isBst(root->left,minV, root->data) and isBst(root->right, root->data,maxV)){
        return true;
    }

    return false;
}

Node* build(){
    int d; cin>>d;

    Node* root=NULL;
    while(d!=-1){
        root = insertBST(root,d);
        cin>>d;
    }

    return root;
}


class LinkedList{
    public:
    Node*head;
    Node*tail;
};

LinkedList flattenALinkedList(Node* root){
    LinkedList l;
    if(root==NULL){
        
        l.head=l.tail=NULL;
        return l;
    }

    if(root->right==NULL and root->left==NULL){
        l.head = l.tail = root;
        return l;
    }

    if(root->left!=NULL and root->right==NULL){
        LinkedList l1 = flattenALinkedList(root->left);
        l1.tail->right = root;
        l.head = l1.head;
        l.tail = root;
        return l;
    }

    if(root->right!=NULL and root->left==NULL){
        LinkedList l1 = flattenALinkedList(root->right);
        root->right = l1.head;
        l.head = root;
        l.tail = l1.tail;
    }

    LinkedList l1 = flattenALinkedList(root->left);
    LinkedList l2 = flattenALinkedList(root->right);
    l1.tail->right = root;
    root->right = l2.head;

    l.head = l1.head;
    l.tail = l2.tail;

    return l;

}

void printIn(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    printIn(root->left);
    printIn(root->right);
    return;
}

int main() {
    
    return 0;
}