#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left=right=NULL;
    }
};

Node* buildTree(){
    Node* root=NULL;
    int d; cin>>d;
    int h; cin>>h;

    root = new Node(d);

    if(h==0){
        root->left = root->right = NULL;
        return root;
    }

    root->left = buildTree();
    root->right = buildTree();    
    
    return root;

}

int sum(Node*root, int k){

    if(root==NULL){
        return 0;
    }

    if(k==1){
        return root->data;
    }

    int ans =0;
    ans+= sum(root->left,k-1) + sum(root->right,k-1);
    return ans;
}

void inOrder(Node* root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    inOrder(root->left);
    inOrder(root->right);

}


int main() {
    Node* root=buildTree();
    // inOrder(root);
    int k; cin>>k;
    cout<<sum(root,3);

    return 0;
}