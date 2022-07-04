/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>res;
        if(root==NULL){
            return res;
        }
        vector<int>v;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            
            if(curr==NULL){
                res.push_back(v);
                v.resize(0);
                
                if(q.size()>0){
                    q.push(NULL);
                }
            }
            else{
                v.push_back(curr->val);
                for(vector<Node*>::iterator it=curr->children.begin(); it!=curr->children.end(); it++){
                    q.push(*it);
                }
            }
        }
        
        return res;
    }
};