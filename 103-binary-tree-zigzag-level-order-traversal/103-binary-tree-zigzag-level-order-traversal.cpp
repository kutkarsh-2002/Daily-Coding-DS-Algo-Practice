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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
       /* 
        vector<int>v;
        bool check=true;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode * curr=q.front();
            q.pop();
            
            if(curr==NULL){
                if(check==true){
                    res.push_back(v);
                    v.clear();
                    
                }else{
                    reverse(v.begin(), v.end());
                    res.push_back(v);
                    v.clear();
                    
                }
                check=!check;
                
                if(q.size()>1){
                    q.push(NULL);
                }
            }else{
                v.push_back(curr->val);
                
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }*/
        
        queue<TreeNode*>q;
        q.push(root);
        int level = 0; 
        
        while (!q.empty()) {
            
            int sz = q.size();  
            vector<int> curr(sz); 
            
            for (int i = 0; i < sz; i++) {
                
                TreeNode* tmp = q.front();
                q.pop();
                
                if (level == 0) {
                    curr[i] = tmp->val;  
                } else {
                    curr[sz - i - 1] = tmp->val; 
                }
                
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            res.push_back(curr); 
            level = !level; 
        }
        
        return res;
        
    }
};