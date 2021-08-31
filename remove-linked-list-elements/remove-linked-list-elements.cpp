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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return NULL;
        }
        if(head->val==val && head->next==NULL){
            delete (head);
            return NULL;
        }
        // if(head->val!=val && head->next==NULL)
        //     return head;
        
        ListNode* curr=head;
        if(curr->val==val){
            while(curr!=NULL && curr->val==val){
                ListNode* temp=curr;
                curr=curr->next;
                delete (temp);
            }
        }
        head=curr;
        if(head==NULL){
            return head;
        }
        else if(head->val!=val){
            ListNode * curr=head->next;
            ListNode *prev=head;
            while(curr!=NULL){
                if(curr->val==val){
                    ListNode *temp=curr;
                    prev->next=temp->next;
                    curr=curr->next;
                    delete (temp);
                }else{
                    prev=prev->next;
                    curr=curr->next;
                }
            }
            
            return head;
        }
        
        
        return head;
       
    }
};