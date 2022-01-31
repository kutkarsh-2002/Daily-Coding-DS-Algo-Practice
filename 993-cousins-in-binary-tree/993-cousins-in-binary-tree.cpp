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
    pair<TreeNode*, int> findingdepth(TreeNode* root, TreeNode* parent, int k, int depth,  pair<TreeNode*, int> &p ){
        if(!root)
            return {};
        findingdepth(root->left, root, k, 1+depth, p);
        
        if(root->val==k){
            p.first=parent;
            p.second=depth;
            
            return p;
        }
        
        findingdepth(root->right, root, k, 1+depth, p);
        
        return p;
         
    }
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root){
            return true;
        }
        
        pair<TreeNode*, int>p1, p2;
        
        findingdepth(root, root, x, 0, p1);
        findingdepth(root, root, y, 0, p2);
        
        return p1.first != p2.first && p1.second==p2.second;
           
    }
};