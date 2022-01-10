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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        /*queue<TreeNode*>q;
        vector<int>v;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            v.push_back(curr->val);
            
            if(curr->left!=NULL){
                q.push(curr->left);
            }
            
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
        
        unordered_set<int>s;
        int pre_sum=0;
        
        for(int i=0; i<v.size(); i++){
            pre_sum+=v[i];
            
            if(pre_sum==targetSum){
                return true;
            }
            
            if(s.find(pre_sum)==s.end()){
                s.insert(pre_sum);
            }
            
            if(s.find(targetSum-pre_sum)!=s.end()){
                return true;
            }
        }
        
        return false;*/
        
        if(root->val==targetSum && root->left==NULL && root->right==NULL){
            return true;
        }
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);
    }
};