/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
//     void dfs(TreeNode* root, int& sum){
//         if(root==NULL)
//             return ;
        
//         if(root->val%2==0){
//             if(root->left!=NULL && root->left->left!=NULL)
//                 sum+=root->left->left->val;
//             if(root->left!=NULL && root->left->right!=NULL)
//                 sum+=root->left->right->val;
            
//             if(root->right!=NULL && root->right->left!=NULL)
//                 sum+=root->right->left->val;
//             if(root->right!=NULL && root->right->right!=NULL)
//                 sum+=root->right->right->val;
            
//         }
        
//         dfs(root->left, sum);
//         dfs(root->right, sum);
        
        
//     }
    
//     int sumEvenGrandparent(TreeNode* root) {
//         int sum=0;
        
//         dfs(root, sum);
        
//         return sum;
//     }
    
    int s=0;
    void find(TreeNode *gp,TreeNode *p, TreeNode * child)
    {
        if(child==NULL) return; 
        if(gp!=NULL&&gp->val%2==0){ s+=child->val;} 
        //make parent to gp, child to parent ,child= child->child 
        find(p,child,child->left);
        find(p,child,child->right);
    }
    int sumEvenGrandparent(TreeNode* root) { 
        
        find(NULL,NULL,root);  //we are passing grandparent(gp),parent(p),child
        return s;
    }
};