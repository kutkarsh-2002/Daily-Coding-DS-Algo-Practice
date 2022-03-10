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
        if(l1==NULL && l2==NULL)
            return NULL;
        
        else if(l2==NULL)
            return l1;
        else if(l1==NULL)
            return l2;
        else{
            
            ListNode* prev1=NULL, *curr1=l1;
            
            //reversing the first linkedlist
            while(curr1!=NULL){
                ListNode* temp=curr1->next;
                curr1->next=prev1;
                prev1=curr1;
                curr1=temp;
            }
            
            ListNode* prev2=NULL, *curr2=l2;
            
            //reversing the second linkedlist
            
            while(curr2!=NULL){
                ListNode* temp=curr2->next;
                curr2->next=prev2;
                prev2=curr2;
                curr2=temp;
            }
            
            int carry=0;
            
            ListNode* head=NULL, *curr=NULL;
            
            while(prev1!=NULL && prev2!=NULL){
                
                if(head==NULL){
                    
                    int temp=prev1->val+prev2->val+carry;
                    
                    if(temp>9){
                        int res=temp%10;
                        carry=temp/10;
                        ListNode* tnode=new ListNode(res);
                        head=tnode;
                        curr=head;
                        
                    }
                    else{
                        ListNode* tnode=new ListNode(temp);
                        head=tnode;
                        curr=head;
                        carry=0;
                    }
                    
                }
                else{
                    
                    int temp=prev1->val+prev2->val+carry;
                    
                    if(temp>9){
                        int res=temp%10;
                        carry=temp/10;
                        ListNode* tnode=new ListNode(res);
                        curr->next=tnode;
                        curr=curr->next;
                        
                    }
                    else{
                        ListNode* tnode=new ListNode(temp);
                        curr->next=tnode;
                        curr=curr->next;
                        carry=0;
                    }
                }
                
                prev1=prev1->next;
                prev2=prev2->next;
            }
            
            // if first likedlist is remaining
            while(prev1!=NULL){
                int temp=prev1->val+carry;
                if(temp>9){
                        int res=temp%10;
                        carry=temp/10;
                        ListNode* tnode=new ListNode(res);
                        curr->next=tnode;
                        curr=curr->next;
                        
                    }
                    else{
                        ListNode* tnode=new ListNode(temp);
                        curr->next=tnode;
                        curr=curr->next;
                        carry=0;
                    }
                
                prev1=prev1->next;
                
            }
            
            //if second linkedlist is remaining
            
            while(prev2!=NULL){
                
                int temp=prev2->val+carry;
                if(temp>9){
                        int res=temp%10;
                        carry=temp/10;
                        ListNode* tnode=new ListNode(res);
                        curr->next=tnode;
                        curr=curr->next;
                        
                    }
                    else{
                        ListNode* tnode=new ListNode(temp);
                        curr->next=tnode;
                        curr=curr->next;
                        carry=0;
                    }
                
                prev2=prev2->next;
            }
            
            // if carry is greater than 0
            
            if(carry!=0){
                ListNode* tnode=new ListNode(carry);
                curr->next=tnode;
                curr=curr->next;
            }
            
            curr->next=NULL;
            
            ListNode* prev=NULL;
            while(head!=NULL){
                ListNode* temp=head->next;
                head->next=prev;
                prev=head;
                head=temp;
            }
            
            return prev;
            
        }
    }
};