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
    void dfs(TreeNode* root, string temp, vector<string>&v){
        if(root==NULL)
            return ;
        
        if(root->left==NULL && root->right==NULL){
            temp+=to_string(root->val);
            v.push_back(temp);
            
            temp.pop_back();
            
            return ;
        }
        
        temp+=to_string(root->val)+"->";
        
        dfs(root->left, temp, v);
        dfs(root->right, temp, v);
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        
        dfs(root, "", v);
        
        return v;
    }
};