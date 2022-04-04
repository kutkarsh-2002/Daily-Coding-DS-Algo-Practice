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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL){
            return NULL;
        }
        ListNode* curr=head;
        int len=0;
        while(curr!=NULL){
            len++;
            curr=curr->next;
        }
        curr=head;
        for(int i=1; i<len-k+1; i++){
            curr=curr->next;
        }
        
        ListNode* trav=head;
        for(int i=1; i<k;i++){
            trav=trav->next;
        }
        int temp=trav->val;
        trav->val=curr->val;
        curr->val=temp;
        return head;
    }
};