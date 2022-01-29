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
    void dfs(TreeNode* root, int level, int & maxlevel, vector<int>&v){
        if(root==NULL)
            return ;
        if(maxlevel<level){
            v.push_back(root->val);
            maxlevel=level;
        }
        dfs(root->right, level+1, maxlevel, v);
        dfs(root->left, level+1, maxlevel, v);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>v;
        if(root==NULL){
            return v;
        }
        int maxlevel=0;
        
        dfs(root, 1, maxlevel, v);
        
        return v;
    }
};