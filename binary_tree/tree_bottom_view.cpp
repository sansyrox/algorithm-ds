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
        data =d;
        left=right=NULL;
    }
};

void tree_bottom_view(Node*root, map<int,int> &m, int i=0){
    if(root==NULL){
        return;
    }

    m[i] = root->data;
    tree_bottom_view(root->right,m,i+1);
    tree_bottom_view(root->left,m,i-1);
    return;

}

int main() {

    Node*root=NULL;
    map<int,int> m;
    tree_bottom_view(root,m,0);

    for(auto j:m){
        cout<<j.second<<" ";
    }

    return 0;
}