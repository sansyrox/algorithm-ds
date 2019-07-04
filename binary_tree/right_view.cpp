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
        left = right = NULL;
    }
};

void leftView(vector<vector<int> > &v, Node* root){
    if(root==NULL){
        return;
    }

    queue<Node*> q;
    q.push(root);

    vector<int> x;
    while(!q.empty()){
        Node* t = q.front();
        x.pb(t->data);
        q.pop();
        if(t==NULL and q.front()==NULL){
            break;
        }

        if(t==NULL){
            v.pb(x);
            q.push(NULL);
            x.clear();
            continue;
        }

        if(t->left){
            q.push(t->left);
        }
        if(t->right){
            q.push(t->right);
        }
    }

    for(auto i:v){
        cout<<i[0]<<" ";
    }
    return;
}

int main() {
    
    return 0;
}