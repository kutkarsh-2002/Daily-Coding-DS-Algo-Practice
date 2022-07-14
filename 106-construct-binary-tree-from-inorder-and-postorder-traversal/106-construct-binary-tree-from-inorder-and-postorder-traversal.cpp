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
    TreeNode* treebuild(vector<int>&postorder, int postr, int poend, vector<int>&inorder, int instr, int inend, unordered_map<int, int>&mp)
    {
        if(postr>poend || instr>inend) return NULL;
        TreeNode* root=new TreeNode(postorder[poend]);
        
        int inRoot=mp[postorder[poend]];
        int numsleft=inRoot-instr;
        
        root->left=treebuild(postorder, postr, postr+numsleft-1, inorder, instr, inRoot-1, mp);
        root->right=treebuild(postorder, postr+numsleft, poend-1, inorder, inRoot+1, inend, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            
        unordered_map<int, int>mp;
            
        for(int i=0; i<inorder.size(); i++){
            mp[inorder[i]]=i;
        }
            
            
        TreeNode* root=treebuild(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mp);
        return root;
    
    }
};