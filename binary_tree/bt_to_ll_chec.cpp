void insertAtTail(TreeNode* &head, TreeNode* tail){
    if(head==NULL){
        head = tail;
    }
    
    TreeNode* temp =head;
    while(temp->right!=NULL){
        temp = temp->right;
    }
    
    temp->right = tail;
} 
 
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL){
        return A;
    }
    
    if(!A->left and !A->right){
        return A;
    }
    
    
    if(!A->left){
        TreeNode* t = flatten(A->right);
        A->right = t;
        return A;
    }
    
    if(!A->right){
        TreeNode* head = flatten(A->left);
        A->left=A->right = NULL;
        insertAtTail(head,A);
        return head;
    }
    
    TreeNode* left = flatten(A->left);
    TreeNode* right = flatten(A->right);
    A->right = right;
    A->left = NULL;
    insertAtTail(left,A);
    
    return left;
    
}


