/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        
        Node* tail=NULL;
        queue<Node*>q;
        q.push(root);
        q.push(NULL);
        
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            
            if(curr==NULL){
                tail->next=NULL;
                tail=tail->next;
                if(q.size()>0){
                    q.push(NULL);
                }
            }else{
                
                if(tail==NULL){
                    tail=curr;
                }else{
                    tail->next=curr;
                    tail=tail->next;
                }
                
                if(curr->left!=NULL){
                    q.push(curr->left);
                }
                
                if(curr->right!=NULL){
                    q.push(curr->right);
                }
            }
        }
        
        return root;
    }
};