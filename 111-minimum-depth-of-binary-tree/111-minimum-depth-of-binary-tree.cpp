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
    /*void depthCalculation(TreeNode*root, int count, int &minimum){
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            minimum=min(minimum, count);
            count=1;
            return ;
        }
        count++;
        depthCalculation(root->left, count, minimum);
        depthCalculation(root->right,count, minimum);
        
        
    }
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int minimum=INT_MAX;
        int count=1;
        depthCalculation(root, count, minimum);
        return minimum;
    }*/
    
    int minDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        
        if(root->right==NULL)
            return 1+minDepth(root->left);
        if(root->left==NULL)
            return 1+minDepth(root->right);
        
        
        return 1+min(minDepth(root->left), minDepth(root->right));
    }
};