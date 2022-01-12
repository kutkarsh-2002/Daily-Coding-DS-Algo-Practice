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
    int widthOfBinaryTree(TreeNode* root) {
        /*
        //This code is unable to handle the situation where we need to include null node in maximun width for every test acses
        
        if(root==NULL){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int maximum=0;
        int count=0;
        int prev=0;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                maximum=max(maximum, count);
                count=0;
                count+=prev;
                prev=0;
                if(q.size()>0){
                    q.push(NULL);
                }
            }else{
                count++;
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
                if(curr->left==NULL && curr->right!=NULL){
                    prev++;
                }
                if(curr->left!=NULL && curr->right==NULL){
                    prev++;
                }
                
            }
        }
        
        return maximum;*/
        
        if (!root)return 0;
        queue<pair<TreeNode*, unsigned long long int>> que;
        que.push({root, 0});
        int width = 0;
        while (que.size() != 0) {
            unsigned long long int left = que.front().second, right = 0;
            int size = que.size();
            while (size-- > 0) {
                pair<TreeNode*, unsigned long long int> rNode = que.front();
                que.pop();
                right = rNode.second;
                if (rNode.first->left) {
                    que.push({rNode.first->left, 2 * rNode.second + 1});
                }
                if (rNode.first->right) {
                    que.push({rNode.first->right, 2 * rNode.second + 2});
                }
            }
            width = max(width, int(right - left + 1));
        }
        return width;
        
    }
};