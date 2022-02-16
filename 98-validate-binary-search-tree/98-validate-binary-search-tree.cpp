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
    bool validation(TreeNode* root, long long min_val, long long max_val){
        if(!root)
            return true;
        
        if(root->val<=min_val || root->val>=max_val)
            return false;
        
        return validation(root->left, min_val, root->val) && validation(root->right, root->val, max_val);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        if(root->left==NULL && root->right==NULL)
            return true;
        long long min_val=LONG_LONG_MIN, max_val=LONG_LONG_MAX;
       return validation(root, min_val, max_val);
    }
};