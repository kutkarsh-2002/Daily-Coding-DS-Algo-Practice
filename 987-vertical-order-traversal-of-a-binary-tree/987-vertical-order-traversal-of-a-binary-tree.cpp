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
    /*void preorder(TreeNode* root, int hd, map<int, vector<int>>&mp){
        if(root==NULL){
            return ;
        }
        mp[hd].push_back(root->val);
        preorder(root->left, hd-1, mp);
        preorder(root->right, hd+1, mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>mat;
        if(root==NULL){
            return mat;
        }
        map<int, vector<int>>mp;
        
        preorder(root, 0, mp);
        
        for(auto x: mp){
            
            vector<int>v=x.second;
            if(v.size()==3){
                sort(v.begin()+1, v.end());
            }else{
                sort(v.begin(), v.end());
            }
            mat.push_back(v);
        }
        
        return mat;
    }*/
    
    void traverse(TreeNode* node, int x, int y,  map<int, multiset<pair<int, int>>>& mp)
        {
            if(!node) return;
            mp[x].insert({y, node->val});
            traverse(node->left, x-1, y+1, mp);
            traverse(node->right, x+1, y+1, mp);
        }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
        {
            map<int, multiset<pair<int, int>>> mp; // [x][y, val]
            traverse(root, 0, 0, mp);
            vector<vector<int>> res;
            for(auto& [x, st] : mp)
            {
                res.push_back({}); //push empty vector to vector matrix
                for(auto& [y, val] : st) 
                    res.back().push_back(val); //push element into prev empty vector 
            }
            return res;
        }
    
};