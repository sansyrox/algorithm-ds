/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define vvi vector<vector<int> >
#define vi vector<int>
#define pb push_back

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

    if (!root)
        return ans;
    
    queue<TreeNode*> q;
    q.push(root);
        
        
        
    while (!q.empty()) {
        // TreeNode* f= q.front();
        int nodeCount = q.size();  
  
        // Dequeue all nodes of current level and  
        // Enqueue all nodes of next level  
        vector<int> temp;
        while (nodeCount > 0) 
        {  
            TreeNode *node = q.front(); 
            
            // cout << node->data << " ";  
            temp.push_back(node->val);
            q.pop();  
            if (node->left != NULL)  
                q.push(node->left);  
            if (node->right != NULL)  
                q.push(node->right);  
            nodeCount--;  
        }  

        ans.push_back(temp);
        temp.clear();
    }
    

        
    return ans;
        
    }
};