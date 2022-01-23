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
    
    void res(TreeNode* root, int &val, int& mindiff){
        if(root==NULL){
            return ;
        }
        res(root->left, val, mindiff);
        if(val>=0){
            mindiff=min(mindiff, (root->val-val));
        }
        val=root->val;
        res(root->right, val, mindiff);
    }
    int minDiffInBST(TreeNode* root) {
        int mindiff=INT_MAX;
        int val=-1;
        res(root, val, mindiff);
        return mindiff;
    }
};