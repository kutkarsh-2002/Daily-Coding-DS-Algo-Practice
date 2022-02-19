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
    
    void traversal(TreeNode* root, int& prev){
        if(root==NULL)
            return ;
        traversal(root->right, prev);
        root->val+=prev;
        prev=root->val;
        traversal(root->left, prev);
        
        
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)
            return NULL;
        int prev=0;
        traversal(root, prev);
        return root;
    }
};