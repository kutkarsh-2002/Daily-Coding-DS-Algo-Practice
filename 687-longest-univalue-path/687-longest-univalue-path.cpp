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
    
    int dfs(TreeNode* root, TreeNode* parent, int count, int &res){
        
        if(root==NULL){
            return 0;
        }
        
        int left=0,  right=0;
        
        left=dfs(root->left, root, count, res);
        right=dfs(root->right, root, count, res);
        
        res=max(res, left+right);
        
        if(parent){
            if(parent->val==root->val){
                return max(left, right)+1;
            }
            else{
                return 0;
            }
        }
        
        return 0;
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        
        if(root==NULL){
            return 0;
        }
        
        int res=0;
        
        dfs(root, NULL, 0, res);
        
        return res;
    }
};