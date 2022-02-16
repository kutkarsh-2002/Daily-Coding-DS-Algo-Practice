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
    int maxLevelSum(TreeNode* root) {
        
        if(!root)
            return -1;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int currlevel=1, currsum=0, max_sum=INT_MIN, min_level=-1;
        
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                if(max_sum<currsum){
                    max_sum=currsum;
                    min_level=currlevel;
                    
                }
                currlevel++;
                currsum=0;
                
                if(q.size()>0){
                    q.push(NULL);
                }
            }else{
                currsum+=curr->val;
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            
        }
        
        return min_level;
    }
};