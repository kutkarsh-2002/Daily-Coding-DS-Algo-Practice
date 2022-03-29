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
    /*void inorder(TreeNode* root, int & ansSum){
        if(root==NULL){
            return;
        }
        inorder(root->left, ansSum);
        ansSum+=root->val;
        inorder(root->right, ansSum);
    }
    
    void dfs(TreeNode* root, int &pl, int &pr){
        if(root==NULL){
            retrun;
        }
        
        if(root->left==NULL && root->right==NULL && flag==true){
            pl+=root-val;
            root->val=0;
            return ;
        }
        else if(root->left==NULL && root->right==NULL && flag==true){
            pr+=root-val;
            root->val=0;
            return ;
        }
        
        dfs(root->left, pl, pr, true);
        pl+=root->val;
        dfs(root->right, pl, pr, false);
        
        
            
    }
    
    int findTilt(TreeNode* root) {
        
        int ansSum=0;
        dfs(root, 0, 0);
        inorder(root, ansSum);
        return ansSum;
        
    }*/
    
    int dfs(TreeNode* root, int &p){
        if(root==NULL){
            return p;
        }
        p+=root->val;
        dfs(root->left, p);
        dfs(root->right, p);
        
        return p;
    }
    void inorder(TreeNode* root, int &ansSum){
        if(root==NULL){
            return ;
        }
        int pl=0, pr=0;
        ansSum+=abs(dfs(root->left, pl)-dfs(root->right, pr));
        
        inorder(root->left, ansSum);
        inorder(root->right, ansSum);
    }
    
    int findTilt(TreeNode* root) {
        
        int ansSum=0;
        inorder(root, ansSum);
        return ansSum;
        
    }
    
    
};