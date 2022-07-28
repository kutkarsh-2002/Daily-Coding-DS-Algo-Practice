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
    void preorder(TreeNode* root, int &count, int mx){
        if(root==NULL) return ;
        
        if(root->val>=mx){
            count++;
            mx=max(mx, root->val);
        }
        
        preorder(root->left, count, mx);
        preorder(root->right, count, mx);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        
        if(root->left==NULL && root->right==NULL) return 1;
        
        int count=0;
        int mx=root->val;
        preorder(root, count, mx);
        return count;
    }
};