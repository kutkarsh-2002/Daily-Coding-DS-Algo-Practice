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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1==NULL){
            return l2;
        }
        else if(l2==NULL){
            return l1;
        }
        else{
            ListNode *head=NULL, *tail=NULL;
            
            while(l1!= NULL && l2!=NULL){
                if(head==NULL){
                    if(l1->val<l2->val){
                        head=l1;
                        l1=l1->next;
                    }else{
                        head=l2;
                        l2=l2->next;
                    }
                    tail=head;
                }
                else{
                    if(l1->val<l2->val){
                        tail->next=l1;
                        l1=l1->next;
                    }else{
                        tail->next=l2;
                        l2=l2->next;
                    }
                    
                    tail=tail->next;
                }
                
            }
            
            while(l1!=NULL){
                tail->next=l1;
                tail=tail->next;
                l1=l1->next;
            }
            while(l2!=NULL){
                tail->next=l2;
                tail=tail->next;
                l2=l2->next;
            }
            
            return head;
        }
    }
};