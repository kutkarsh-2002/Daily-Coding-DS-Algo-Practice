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
    int depthBT(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int L=depthBT(root->left);
        int R=depthBT(root->right);
        
        if(L>R){
            return L+1;
        }else{
            return R+1;
        }
    }
    
    void dlSum(TreeNode* root, int depth, int &h, int &sum){
        if(root==NULL){
            return ;
        }
        
        if(root->left==NULL && root->right==NULL && depth+1==h){
            sum+=root->val;
        }
        
        dlSum(root->left, depth+1, h, sum);
        dlSum(root->right, depth+1, h, sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        
        int h=depthBT(root);
        //cout<<h<<endl;
        
        int sum=0;
        dlSum(root, 0, h, sum);
        
        return sum;
        
    }
};