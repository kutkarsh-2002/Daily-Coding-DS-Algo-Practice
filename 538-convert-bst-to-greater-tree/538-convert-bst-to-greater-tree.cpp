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
    
    void dfs(TreeNode* root, int &p){
        if(root==NULL){
            return ;
        }
        
        dfs(root->right, p);
        root->val+=p;
        p=root->val;
        dfs(root->left, p);
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL){
            return NULL;
        }
        
        if(root->left==NULL && root->right==NULL){
            return root;
        }
        int p=0;
        dfs(root, p);
        
        return root;
    }
};