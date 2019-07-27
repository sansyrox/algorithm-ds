void corrBST(Node* root, Node* l, Node* r, Node* &mis1, Node* &mis2) {
    if(!root){
        return ;
    }
    
    if(l and root->data>=l->data){
        mis1 = root;
    }
    
    if(r and root->data<=r->data){
        mis2 = root;
    }
    
    corrBST(root->left,root,r,mis1,mis2);
    corrBST(root->right,l,root,mis1,mis2);
}

struct Node *correctBST( struct Node* root )
{
    // add code here.
    Node* missing1=NULL,*missing2=NULL;
    corrBST(root,NULL,NULL,missing1,missing2);
    
    if(missing1 and missing2){
        swap(missing1->data,missing2->data);
        Node* l1=missing1->left,*r1 = missing1->right;
        Node* l2 = missing2->left,*r2 = missing2->right;
        
        swap(missing1,missing2); //ye bhi kar sakte hai
        
    }
    
    return root;
    
}
