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
    TreeNode* constructBST(TreeNode* &root, int element){
        if(!root){
            return root=new TreeNode(element);
        }
        
        if(root->val>element){
            root->left=constructBST(root->left, element);
        }
        else{
            root->right=constructBST(root->right, element);
        }
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.size()==0)
            return NULL;
        
        TreeNode* root=NULL;
        
        for(auto x: preorder){
            constructBST(root, x);
        }
        
        return root;
    }
};