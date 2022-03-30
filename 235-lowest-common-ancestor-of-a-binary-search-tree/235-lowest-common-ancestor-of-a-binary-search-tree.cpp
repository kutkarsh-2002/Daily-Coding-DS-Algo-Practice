/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* n1, TreeNode* n2) {
        
        if(root==NULL){
            return NULL;
        }
        
        if(root->val==n1->val || root->val==n2->val){
            return root;
        }
        
        TreeNode* lca1=lowestCommonAncestor(root->left, n1, n2);
        TreeNode* lca2=lowestCommonAncestor(root->right, n1, n2);
        
        if(lca1!=NULL && lca2!=NULL){
            return root;
        }
        
        if(lca1!=NULL){
            return lca1;
        }
        else{
            return lca2;
        }
    }
};