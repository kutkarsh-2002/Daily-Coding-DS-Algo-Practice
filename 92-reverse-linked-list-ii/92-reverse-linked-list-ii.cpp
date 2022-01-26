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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
       if(head==NULL){
           return NULL;
       }
        if(head->next==NULL){
            return head;
        }
        ListNode* curr=head, *prev=NULL;
        int count=1;
        while(count<left){
            prev=curr;
            curr=curr->next;
            count++;
        }
        ListNode* tempL=curr;
        ListNode* previous=NULL, *temp=NULL;
        while(count<=right){
            temp=curr->next;
            curr->next=previous;
            previous=curr;
            curr=temp;
            count++;
        }
        if(prev==NULL){
            
            tempL->next=temp;
            return previous;
        }
        else{
            prev->next=previous;
            tempL->next=temp;
            return head;
        }
        
    }
};