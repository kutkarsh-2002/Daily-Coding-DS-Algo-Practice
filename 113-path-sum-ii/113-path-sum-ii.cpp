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
    
//     void getAllpaths(TreeNode* root, vector<int>temp, vector<vector<int>>&mat, int targetSum){
//         if(root==NULL){
//             return ;
//         }
        
//         if(root->left==NULL && root->right==NULL && root->val==targetSum){
//             temp.push_back(root->val);
//             mat.push_back(temp);
//             return ;
            
//         }
        
//         temp.push_back(root->val);
//         getAllpaths(root->left, temp, mat, targetSum-root->val);
//         getAllpaths(root->right, temp, mat, targetSum-root->val);
//     }
//     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//         vector<vector<int>>mat;
//         getAllpaths(root, {}, mat,targetSum);
//         return mat;
        
//     }
    
    
    void pathStore(TreeNode* root, vector<int>& path, int targetSum, vector<vector<int>>& res){
        if(root == NULL)
            return;	
        path.push_back(root->val);
        if(root->right == NULL and root->left == NULL and targetSum == root->val){
            res.push_back(path);
            path.pop_back();
            return;
        }
        pathStore(root->left, path, targetSum - root->val, res);
        pathStore(root->right, path, targetSum - root->val, res); 
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        vector<vector<int>> res;
        pathStore(root, path, targetSum, res);
        return res;
    }
};