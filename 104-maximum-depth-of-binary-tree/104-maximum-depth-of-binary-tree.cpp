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
    
    /*void depthCalculation(TreeNode*root, int count, int &maximum){
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            count++;
            maximum=min(maximum, count);
            return ;
        }
        count++;
        depthCalculation(root->left, count, maximum);
        depthCalculation(root->right,count, maximum);
        
        
    }
    
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int maximum=INT_MAX;
        int count=1;
        depthCalculation(root, 0, maximum);
        return maximum;
    }*/
    int getAns(TreeNode* root){
        if(!root)
            return 0;
        int L=getAns(root->left);
        int R=getAns(root->right);
        
        if(L>R){
            return L+1;
        }else{
            return R+1;
        }
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        return getAns(root);
    }
    
    
};