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
    
    /*int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        else{
            return 1+max(height(root->left), height(root->right));
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int dr=1+height(root->left)+height(root->right);
        
        int dlt=diameterOfBinaryTree(root->left);
        int drt=diameterOfBinaryTree(root->right);
        
        return max(dr, max(dlt, drt));
    }*/
    
    int result(TreeNode* root, int &d){
        if(root==NULL){
            return 0;
        }
        int lh=result(root->left, d);
        int rh=result(root->right, d);
        
        d=max(d, lh+rh);
        
        return 1+max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int d=0;
        result(root, d);
        return d;
    }
};