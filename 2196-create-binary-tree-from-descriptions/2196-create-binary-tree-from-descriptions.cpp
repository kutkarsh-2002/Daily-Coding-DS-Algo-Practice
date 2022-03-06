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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        if(descriptions.size()==0){
            return NULL;
        }
        unordered_map<int, TreeNode*>mp;
        unordered_set<int>childRoot;
        
        
        int parent, child, dir;
        
        for(int i=0; i<descriptions.size(); i++){
            parent=descriptions[i][0];
            child=descriptions[i][1];
            dir=descriptions[i][2];
            
            if(mp.find(parent)==mp.end()){
                TreeNode* parentNode=new TreeNode(parent);
                mp.insert({parent, parentNode});
            }
            
            if(mp.find(child)==mp.end()){
                TreeNode* childNode=new TreeNode(child);
                mp.insert({child, childNode});
            }
            
            childRoot.insert(child);
            if(dir==1){
                mp[parent]->left=mp[child];
            }else{
                mp[parent]->right=mp[child];
            }
            
            
        }
        
        for(int i=0; i<descriptions.size(); i++){
            if(!childRoot.count(descriptions[i][0])){
                return mp[descriptions[i][0]];
            }
        }
        return NULL;
    }
};