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
    void preorder(TreeNode* root, int &ans, unordered_map<int, int>&mp){
        if(!root) return ;
        
        mp[root->val]++;
        
        if(root->left==NULL && root->right==NULL){
            
            
            int c=0;
            
            for(auto x:mp){
                if(x.second%2!=0){
                    c++;
                }
            }
            
            if(c==0 || c==1) ans++;
            
            mp[root->val]--;
            
            return ;
            
        }
        
        preorder(root->left, ans, mp);
        preorder(root->right, ans, mp);
        
        mp[root->val]--;
    }
    
    
    int pseudoPalindromicPaths (TreeNode* root) {
        
        unordered_map<int, int>mp;
        int ans=0;
        
        preorder(root, ans, mp);
        
        return ans;
    }
};