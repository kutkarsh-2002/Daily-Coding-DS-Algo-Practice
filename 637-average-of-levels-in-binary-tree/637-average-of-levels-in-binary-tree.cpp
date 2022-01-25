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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>v;
        double sum=0;
        int count=0;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                double ans=sum/count;
                v.push_back(ans);
                sum=0;
                count=0;
                if(q.size()>0){
                    q.push(NULL);
                }
            }else{
                sum+=curr->val;
                count++;
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