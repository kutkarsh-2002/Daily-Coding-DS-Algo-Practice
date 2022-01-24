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
    void inorder(TreeNode* root, unordered_map<int, int>&mp){
        if(root==NULL){
            return ;
        }
        inorder(root->left, mp);
        mp[root->val]++;
        inorder(root->right, mp);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>v;
        if(root==NULL){
            return v;
        }
        
        unordered_map<int, int>mp;
        inorder(root, mp);
        
        int mode=1;
        for(auto x:mp){
            if(mode<x.second){
                if(!v.empty()){
                    v.clear();
                }
                mode=x.second;
                v.push_back(x.first);
            }else if(mode==x.second){
                v.push_back(x.first);
            }else if(mode==1){
                v.push_back(x.first);
            }
        }
        
        return v;
    }
};