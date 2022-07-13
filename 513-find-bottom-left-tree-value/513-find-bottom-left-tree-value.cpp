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
    int findBottomLeftValue(TreeNode* root) {
        if(root==NULL) return -1;
        
        if(root->left==NULL && root->right==NULL) return root->val;
        
        queue<TreeNode*>q;
        q.push(root);
        //int res=(root->left==NULL)?root->right->val:root->val;
//         bool flag=false;
        
//         while(!q.empty()){
//             for(int i=q.size()-1, flag=false; i>=0; i--){
//                 TreeNode* curr=q.front();
//                 q.pop();
                
//                 if(curr->left!=NULL && flag==false){
//                     res=curr->left->val;
//                     q.push(curr->left);
//                     flag=true;
//                 }
//                 else if(curr->left!=NULL){
//                     q.push(curr->left);
//                 }
                
//                 if(curr->right!=NULL && curr->left==NULL && flag==false){
//                     res=curr->right->val;
//                     q.push(curr->right);
//                     flag=true;
//                 }
//                 else if(curr->right!=NULL){
//                     q.push(curr->right);
//                 }
                
//             }
//         }
        
        int res=root->val;;
        
        while(!q.empty()){
            int size=q.size();
            
            for(int i=0; i<size; i++){
                TreeNode* curr=q.front();
                q.pop();
                res=curr->val;
                //cout<<res<<endl;
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
            }
        }
        
        return res;
    }
};