#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Node{

public:
    int data;
    Node*left;
    Node* right;

    Node(int d){
        data=d;
        left=right=NULL;
    }

};

Node* buildFromArray(vector<int> arr, int e, int i=0){
    
    
    if(i>e){
        return NULL;
    }

    if(arr[i]==-1){
        return NULL;
    }

    Node*root = new Node(arr[i]);
    root->left = buildFromArray(arr,e,1<<i);
    root->right = buildFromArray(arr,e,(1<<i)+1);

    return root;


}


void traversal(Node* root, unordered_map<int, vector<int> > &um, int i=0){
    if(root==NULL){
        return;
    }
        um[i].pb(root->data);

    traversal(root->left,um,i-1);
    traversal(root->right,um,i+1);
    return;
}

void levelOreder(Node* root){
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* t = q.front();
        q.pop();
        cout<<t->data<<" ";
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
    }
}

int main() {
    unordered_map<int, vector<int> > um;
    int n; cin>>n;
    vector<int> a;
    for(int i=0; i<((1<<n)-1 ) ; i++){
        int t; cin>>t;
        a.pb(t);
    }

    // for(auto j:a){
    //     cout<<j<<" ";
    // }
    // cout<<endl;
    Node* root = buildFromArray(a,a.size()-1, 0);

    levelOreder(root);
    traversal(root,um,0);

    levelOreder(root);

    // for(auto i:um){
    //     for(auto j:i.second){
    //         cout<<j<<" ";
    //     }cout<<endl;
    // }


    return 0;
}