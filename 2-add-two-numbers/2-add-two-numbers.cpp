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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
 
               
        ListNode *curr1=l1, *curr2=l2;
        ListNode* head=NULL, *curr=NULL;
        
        int carry=0;
        while(curr1!=NULL && curr2!=NULL){
            
            int x=curr1->val+curr2->val+carry;
            carry=0;
            
            if(x>9){
                int rem=x%10;
                carry=x/10;
                if(head==NULL){
                    ListNode* temp=new ListNode(rem);
                    head=temp;
                    curr=head;
                }else{
                    ListNode* temp=new ListNode(rem);
                    curr->next=temp;
                    curr=curr->next;
                }
                
            }
            else{
                if(head==NULL){
                    ListNode* temp=new ListNode(x);
                    head=temp;
                    curr=head;
                }else{
                    ListNode* temp=new ListNode(x);
                    curr->next=temp;
                    curr=curr->next;
                }
            }
            
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        
        while(curr1!=NULL){
            int x=curr1->val+carry;
            carry=0;
            if(x>9){
                int rem=x%10;
                carry=x/10;
                ListNode* temp=new ListNode(rem);
                curr->next=temp;
                curr=curr->next;
            }else{
                ListNode* temp=new ListNode(x);
                curr->next=temp;
                curr=curr->next;
            }
            
            curr1=curr1->next;
        }
        
        while(curr2!=NULL){
            int x=curr2->val+carry;
            carry=0;
            if(x>9){
                int rem=x%10;
                carry=x/10;
                ListNode* temp=new ListNode(rem);
                curr->next=temp;
                curr=curr->next;
            }else{
                ListNode* temp=new ListNode(x);
                curr->next=temp;
                curr=curr->next;
            }
            
            curr2=curr2->next;
        }
        
        if(carry>0){
            ListNode* temp=new ListNode(carry);
            curr->next=temp;
            curr=curr->next;
        }
        curr->next=NULL;
        return head;
    }
};