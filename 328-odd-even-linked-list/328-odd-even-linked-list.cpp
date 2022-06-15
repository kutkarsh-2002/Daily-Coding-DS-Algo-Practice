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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        
        if(head->next==NULL)
            return head;
        
        ListNode* curr=head;
        ListNode* currO=NULL, *tailO=NULL, *currE=NULL, *tailE=NULL;
        int n=0;
        
        while(curr!=NULL){
            n++;
            curr=curr->next;
        }
        
        curr=head;
        int i=1;
        
        while(curr!=NULL && i<=n){
            ListNode* temp=new ListNode(curr->val);
            if(i%2==1){
                if(currO==NULL){
                    currO=temp;
                    tailO=temp;
                }
                else{
                    tailO->next=temp;
                    tailO=tailO->next;
                }
            }
            else{
                if(currE==NULL){
                    currE=temp;
                    tailE=temp;
                }else{
                    tailE->next=temp;
                    tailE=tailE->next;
                }
            }
            
            i++;
            curr=curr->next;
        }
        
        tailO->next=currE;
        
        if(tailE!=NULL){
            tailE->next=NULL;
        }
        
        return currO;
    }
};