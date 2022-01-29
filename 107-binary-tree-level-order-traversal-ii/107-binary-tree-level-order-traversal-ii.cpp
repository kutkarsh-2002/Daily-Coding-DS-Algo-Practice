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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>mat;
        
        if(!root)
            return mat;
        
        map<int, vector<int>>mp;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int l=0;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            
            if(curr==NULL){
                l++;
                if(q.size()>0){
                    q.push(NULL);
                }
            }else{
                mp[l].push_back(curr->val);
                
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                
            }
            
        }
        
        for(auto it=mp.rbegin(); it!=mp.rend(); it++){
            mat.push_back(it->second);
        }
        
        return mat;
    }
};