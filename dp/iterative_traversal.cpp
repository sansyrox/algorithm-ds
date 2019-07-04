#include<iostream>
#include<bits/stdc++.h>
#include<unordered_map>
#define ll long long
#define mp make_pair
#define pb push_back
using namespace std;

struct node{
    int val;
    node *left, *right;
    node(int x) {
        val = x;
        left = right = NULL;
    }
};

unordered_map< node*, int > cnt;

void traversal_trick(node* root){
    stack<node*> S;
    S.push(root);
    while(!S.empty()){
        node* cur = S.top();
        if(cur==NULL) {S.pop(); continue;}
        
        if(cnt[cur]==0) S.push(cur->left);
        else if(cnt[cur]==1) cout<<cur->val<<" ";
        else if(cnt[cur]==2) S.push(cur->right);
        else S.pop();
        cnt[cur]++;
    }
}

int main() {
    
    

    return 0;
}