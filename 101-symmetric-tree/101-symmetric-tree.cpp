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
   /* void preorder(TreeNode* root, vector<int>&v1){
        if(!root)
        {
            v1.push_back(-101);
            return ;
        }
        v1.push_back(root->val);
        preorder(root->left, v1);
        preorder(root->right, v1);
    }
    
    void store(TreeNode* root, vector<int>&v2){
        if(!root)
        {
            v2.push_back(-101);
            return ;
        }
        v2.push_back(root->val);
        store(root->right, v2);
        store(root->left, v2);
        
    }
    bool isSymmetric(TreeNode* root) {
        
        if(root==NULL)
            return true;
        
        if(root->left==NULL && root->right==NULL){
            return true;
        }
        
        vector<int>v1;
        vector<int>v2;
        
        preorder(root->left, v1);
        store(root->right, v2);
        
        if(v1.size()!=v2.size())
            return false;
        else{
            for(int i=0; i<v1.size(); i++){
                if(v1[i]!=v2[i])
                    return false;
            }
            
            return true;
        }
    }*/
    
    bool isMirror(TreeNode* root1, TreeNode* root2){
	// If both trees are empty, then they are mirror images
        if(!root1 && !root2)
            return true;
        
        if(root1 && root2 && root1->val == root2->val)
            return isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left);
			
		// if none of above conditions is true then root1 and root2 are not mirror images
        return false;
    }
    
	// Returns true if a tree is symmetric i.e. mirror image of itself
    bool isSymmetric(TreeNode* root) {
		// Check if tree is mirror of itself
        return isMirror(root, root);
    }
    
};
