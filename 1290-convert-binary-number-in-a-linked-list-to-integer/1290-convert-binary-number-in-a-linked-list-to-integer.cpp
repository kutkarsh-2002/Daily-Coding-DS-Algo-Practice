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
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        
        string x="";
        ListNode* curr=head;
        while(curr!=NULL){
            x+=to_string(curr->val);
            curr=curr->next;
        }
        
        int res=0;
        res=stoi(x, 0, 2);
        
        return res;
    }
};