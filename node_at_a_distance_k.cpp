/*This is a function problem.You only need to complete the function given below*/
/* A binary Tree node
struct node
{
    int data;
    struct node *left, *right;
}; */
/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
void printkdistanceNodeDown(node *root, int k)
{
// Your code here
    if(k==0||!root){
        return;
    }
    
    cout<<root->data<<" ";
    printkdistanceNodeDown(root->left,k-1);
    printkdistanceNodeDown(root->right,k-1);
}
/* Prints all nodes at distance k from a given target node.
 The k distant nodes may be upward or downward.  This function
 Returns distance of root from target node, it returns -1 if target
 node is not present in tree rooted with root. */
class Graph{
    unordered_map<node*,list<node*> > adjList;
    
    public:
    
    void addEdge(node* root){
        if(root==NULL){
            return;
        }
        
        if(root->right){
            
            adjList[root->right].push_back(root);
            adjList[root].push_back(root->right);
        }
        
        if(root->left){
            
            adjList[root->left].push_back(root);
            adjList[root].push_back(root->left);
        }
        
        
        
        
        addEdge(root->right);    
        addEdge(root->left);
    }
    
    
    void distanceFromTarget(node* target, int k){
        unordered_map<node*,bool> visited;
        unordered_map<node*,int> distance;
        queue<node*> q;
        q.push(target);
        visited[target] = true;
        distance[target] = 0;
        
        while(!q.empty()){
            node* f = q.front();
            q.pop();
            
            for(auto i:adjList[f]){
                if(!visited[i]){
                    visited[i] = true;
                    q.push(i);
                    distance[i] = distance[f] + 1; 
                }
            }
        }
        
        
        for(auto i:distance){
            if(i.second==k){
                cout<<i.first->data<<" ";
            }
        }
        
        
        return;
        
    }
    
    
};
 
 
 
int printkdistanceNode(node* root, node* target , int k)
{
// Your code here
Graph g;
g.addEdge(root);
g.distanceFromTarget(target,k);
}