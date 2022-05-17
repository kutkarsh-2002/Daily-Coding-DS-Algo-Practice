/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* preorder(TreeNode* cloned, TreeNode* target){
        
        if(cloned==NULL)
            return NULL;
        
        if(target->val==cloned->val){
            return cloned;
           
        }
        
        return (preorder(cloned->left, target)!=NULL)?preorder(cloned->left, target):preorder(cloned->right, target);
        
    }
    
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==NULL){
            return NULL;
        }
        
       return preorder(cloned, target);
        
    }
};