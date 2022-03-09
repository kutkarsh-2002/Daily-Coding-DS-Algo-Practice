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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* curr=head, *prev=NULL;
        while(curr!=NULL && curr->next!=NULL){
            if(head->val==head->next->val){
                head=head->next;
                curr=head;
            }
            else if(curr->val==curr->next->val){
                curr=curr->next;
                prev->next=curr;
            }else{
                prev=curr;
                curr=curr->next;
            }
        }
        
        return head;
    }
};