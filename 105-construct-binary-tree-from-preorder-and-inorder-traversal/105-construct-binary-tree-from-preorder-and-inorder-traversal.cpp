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
    
    TreeNode* treebuild(vector<int>&preorder, int prestr, int preend, vector<int>&inorder, int instr, int inend, unordered_map<int, int>&mp)
    {
        if(prestr>preend || instr>inend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestr]);
        
        int inRoot=mp[preorder[prestr]];
        int numsleft=inRoot-instr;
        
        root->left=treebuild(preorder, prestr+1, prestr+numsleft, inorder, instr, inRoot-1, mp);
        root->right=treebuild(preorder, prestr+numsleft+1, preend, inorder, inRoot+1, inend, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
        
        TreeNode* root=treebuild(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    }
};