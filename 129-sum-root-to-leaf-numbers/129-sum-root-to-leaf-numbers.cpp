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
    
    void sumRtl(TreeNode* root, int & sum, int temp, bool &flag){
        if(!root)
            return ;
        
        if(root->left==NULL && root->right==NULL){
            temp=temp*10+root->val;
            sum+=temp;
            return ;
        }
        
        if(flag==true){
            flag=false;
        }else{
            temp=temp*10+root->val;
        }
        sumRtl(root->left, sum, temp, flag);
        sumRtl(root->right, sum, temp, flag);
    }
    int sumNumbers(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return root->val;
        int sum=0, temp=root->val;
        bool flag=true;
        sumRtl(root, sum, temp, flag);
        
        return sum;
    }
};