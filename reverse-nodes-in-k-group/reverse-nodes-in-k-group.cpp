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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* curr=head, *prev=NULL;
        ListNode *temp=NULL;
        int n=0;
        while(curr!=NULL){
            n++;
            curr=curr->next;
        }
        if(n<k){
            return head;
        }
        
        n=0;
        curr=head;
        int count=0;
        while(curr!=NULL && count<k){
                temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
                count++;
        }
        
        
        if(temp!=NULL){
            
            head->next=reverseKGroup(temp, k);;
        }
        return prev;
            
    }
};