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
   
    void leftlsum(TreeNode* root, int &sum, bool flag){
        if(root==NULL)
            return ;
        
        if(root->left==NULL && root->right==NULL && flag==true)
        {
            sum+=root->val;
            return ;
        }
        leftlsum(root->left, sum, true);
        leftlsum(root->right, sum, false);
        
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)
            return 0;
        
        
        int sum=0;
        bool flag=false;
        leftlsum(root, sum, flag);
        return sum;
    }
};