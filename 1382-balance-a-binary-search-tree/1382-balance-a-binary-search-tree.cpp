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
    
    void inorder(TreeNode* root, vector<int>&v){
        if(!root)
        return ;

        inorder(root->left, v);
        v.push_back(root->val);
        inorder(root->right, v);
}
TreeNode* constructBST(int l, int r, vector<int>&v){
    if(l>r)
    return NULL;
    
    int mid=(l+r)/2;
    
    TreeNode* root=new TreeNode(v[mid]);
    
    root->left=constructBST(l, mid-1, v);
    root->right=constructBST(mid+1, r, v);
    
    return root;
}
    TreeNode* balanceBST(TreeNode* root) {
        
        if(root==NULL)
        return NULL;

        if(root->left==NULL && root->right==NULL)
        return root;

        vector<int>v;
        inorder(root, v);
        sort(v.begin(), v.end());
        int l=0, r=v.size()-1;
        return constructBST(l, r, v);
    }
};