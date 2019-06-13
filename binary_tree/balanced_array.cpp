#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back

class Node{
    public:
    int d;
    Node* left;
    Node* right;

    Node(int d){
        this->d = d;
        left=right=NULL;
    }
};

Node* buildFromArray(int *arr, int s, int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;

    Node* root = new Node(arr[mid]);
    root->left = buildFromArray(arr,s,mid-1);
    root->right = buildFromArray(arr,mid+1,e);

    return root;

}

Node* createTreeFromTrav(int *in, int *pre, int s, int e){
    static int i = 0;
    
    if(s>e){
        return NULL;
    }

    Node* root = new Node(pre[i]);

    int index = -1;
    for(int j=s; i<=e; j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }

    i++;
    root->left = createTreeFromTrav(in,pre,s,index-1);
    root->right =  createTreeFromTrav(in,pre,index+1,e);
    return root;



}


int main() {
    
    return 0;
}