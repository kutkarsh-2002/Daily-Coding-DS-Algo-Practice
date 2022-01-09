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
    vector<int> largestValues(TreeNode* root) {
        vector<int>v;
        if(root==NULL){
            return v;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int maximum=INT_MIN;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                v.push_back(maximum);
                maximum=INT_MIN;
                if(q.size()>0){
                    q.push(NULL);
                }
            }else{
                maximum=max(maximum, curr->val);
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
        
        return v;
    }
};