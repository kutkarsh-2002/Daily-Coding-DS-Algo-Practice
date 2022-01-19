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
    void helper(TreeNode* root,vector<int>&v){
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL){
            v.push_back(root->val);
            return ;
            
        }
        
        helper(root->left, v);
        helper(root->right, v);
    }
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL){
            return -1;
        }
        
        if(root->left==NULL && root->right==NULL){
            return -1;
        }
        vector<int>v;
        helper(root, v);
        sort(v.begin(), v.end());
        
        for(int i=1; i<v.size(); i++){
            if(v[i-1]<v[i]){
                return v[i];
                break;
            }
        }
        
        return -1;
        
    }
};