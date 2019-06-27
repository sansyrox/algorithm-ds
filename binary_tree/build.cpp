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

Node* buildTree(){
    int d; 
    cin>>d;
    
    if(d==-1){
        return NULL;
    }

    Node* root = new Node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(Node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}

void printIn(Node* root){
    if(root==NULL){
        return;
    }

    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(Node* root){
    if(root==NULL){
        return;
    }

    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

void printKthLevel(Node* root, int k){
    if(root==NULL){
        return;
    }

    if(k==1) cout<<root->data<<" ";

    printKthLevel(root->left, k-1);
    printKthLevel(root->right, k-1);
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL and root->right==NULL){
        return 1;
    }

    return 1 + max(height(root->left),height(root->right));


}

void bfs(Node* head){
    queue<Node*> q;

    q.push(head);
    q.push(NULL);

    while(!q.empty()){
        Node* t = q.front();

        if(t==NULL){
            q.push(NULL);
            q.pop();
            if(q.front()==NULL) break;
            cout<<endl;


            // m2
            // cout<<endl;
            //  q.pop()
            // if(!q.empty())q.push(NULL)
        }
        else {
        cout<<t->data<<" ";
        q.pop();

        if(t->left!=NULL) q.push(t->left);
        if(t->right!=NULL) q.push(t->right); 
        }
    }
}

int returnSum(Node* root){
    if(root==NULL){
        return 0;
    }

    if(root->left==NULL and root->right==NULL){
        return root->data;
    }

    return root->data + returnSum(root->left) + returnSum(root->right);

}

int diameter(Node* root){
    if(root==NULL) {
        return 0;
    }
    int h1 = height(root->left);
    int h2 = height(root->right);

    int op1 = h1+h2;
    return max(
        op1,max(
            diameter(root->left),
            diameter(root->right)
        )
    );
}

class Pair{
    public:
    int height;
    int diameter;
};

Pair fastDiameter(Node* root){
    Pair p;
    if(root==NULL){
        p.diameter = p.height =0;
        return p;
    }

    Pair left = fastDiameter(root->left);
    Pair right = fastDiameter(root->right);

    p.height = max(left.height,right.height)+1;
    p.diameter = max(left.height+right.height, max(left.diameter,right.diameter));
    return p;
}

int replaceWithSum(Node* &head){

    if(head==NULL){
        return 0;
    }

    if(head->left==NULL and head->right==NULL){
        return head->data;
    }

    int temp = head->data;
    head->data = replaceWithSum(head->left) + replaceWithSum(head->right);

    return temp + head->data;


}

// bool ifNodeExists(struct Node* node, int key) 
// { 
//     if (node == NULL) 
//         return false; 
  
//     if (node->data == key) 
//         return true; 
  
//     /* then recur on left sutree */
//     bool res1 = ifNodeExists(node->left, key); 
  
//     /* now recur on right subtree */
//     bool res2 = ifNodeExists(node->right, key); 
  
//     return res1 || res2; 
// } 


class Pair1{
    public:
    int height;
    bool isBalanced;
};

Pair1 isHeightBalanced(Node* root){
    if(root==NULL){
        Pair1 p;
        p.height=0,p.isBalanced=true;
        return p;
    }

    Pair1 p;
    p.height = 1 + max(isHeightBalanced(root->left).height,isHeightBalanced(root->right).height);

    p.isBalanced = abs(isHeightBalanced(root->left).height-isHeightBalanced(root->right).height)<=1  and (isHeightBalanced(root->left).isBalanced and isHeightBalanced(root->right).isBalanced) ;

    return p;

}

// 3 4 -1 6 -1 -1 5 1 -1 -1 -1
int main() {
    Node* root = buildTree();
    // print(root);
    // cout<<endl;
    // printIn(root);
    // cout<<endl;
    // printPost(root);
    
    // cout<<endl;
    // int h = height(root);

    // cout<<endl;
    // for(int i=1; i<=h; i++){
    //     printKthLevel(root,i);
    //     cout<<endl;
    // }

    bfs(root);
    // print(root);
    cout<<endl;
    replaceWithSum(root);
    bfs(root);


    return 0;
}