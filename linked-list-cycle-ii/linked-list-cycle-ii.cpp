/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return NULL;
        }
        ListNode* first=head;
        ListNode* second=head;
        
        while(first!=NULL && first->next!=NULL){
            second=second->next;
            first=first->next->next;
            if(first==second){
                break;
            }
        }
        if(first!=second){
            return NULL;
        }
        else{
            second=head;
            if(first==second){
                return second;
            }
            while(second->next!=first->next){
                second=second->next;
                first=first->next;
                
            }
            
        }
        return second->next;
    }
};