/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    // ListNode* midfn(ListNode* head, ListNode* tail)
    // {
    //     ListNode* slow=head, *fast=head;
    //     while(fast!=tail && fast->next!=tail)
    //     {
    //         fast=fast->next->next;
    //         slow=slow->next;
    //     }
    //     return slow;
    // }
    TreeNode* constructBST(vector<int>&v, int l, int r){
        if(l>r)
            return NULL;
        // ListNode* mid=midfn(head, tail);
        // cout<<mid->val<<" ";
        
        int mid=(l+r)/2;
        
        TreeNode* root=new TreeNode(v[mid]);
        //il=mid;
        root->left=constructBST(v, l, mid-1);
        root->right=constructBST(v, mid+1, r);
        return root;
        
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        int l=0, r=v.size()-1;
       return constructBST(v, l, r);
    }
};