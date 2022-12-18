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
    
    void inorder1(TreeNode* root1, vector<int>&l1){
        
        if(root1==NULL){
            return ;
        }
        
        if(root1->left==NULL && root1->right==NULL) l1.push_back(root1->val);
        
        inorder1(root1->left, l1);
        inorder1(root1->right, l1);
    }
    
    void inorder2(TreeNode* root2, vector<int>&l2){
        
        if(root2==NULL){
            return ;
        }
        
        if(root2->left==NULL && root2->right==NULL) l2.push_back(root2->val);
        
        inorder2(root2->left, l2);
        inorder2(root2->right, l2);
    }
    
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>l1;
        vector<int>l2;
        
        inorder1(root1, l1);
        inorder2(root2, l2);
        
        if(l1.size()!=l2.size()) return false;
        
        for(int i=0; i<l1.size(); i++){
            if(l1[i]!=l2[i]) return false;
        }
        
        return true;
    }
};