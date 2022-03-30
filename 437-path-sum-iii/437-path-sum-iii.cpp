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
    void dfs(TreeNode* root, int sum, int &targetSum, int &count){
        if(root==NULL){
            return ;
        }
        sum+=root->val;
        if(sum==targetSum){
            count++;
            
        }
        dfs(root->left, sum, targetSum, count);
        dfs(root->right, sum, targetSum, count);
    }
    
    void preorder(TreeNode* root, int & count, int &targetSum){
        if(root==NULL){
            return ;
        }
        int sum=0;
        dfs(root, sum, targetSum, count);
        
        preorder(root->left, count, targetSum);
        preorder(root->right, count, targetSum);
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        int count=0;
        preorder(root, count, targetSum);
        return count;
    }
};