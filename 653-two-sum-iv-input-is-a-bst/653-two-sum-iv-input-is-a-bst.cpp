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
    bool find(TreeNode* root, unordered_set<int>&st, int &k){
        if(root==NULL){
            return false;
        }
        if(st.find(k-root->val)!=st.end()){
            return true;
        }else{
            st.insert(root->val);
        }
        
        
        return (find(root->left, st, k)||find(root->right, st, k));
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL){
            return false;
        }
        unordered_set<int>st;
        return find(root, st, k);
        
    }
};