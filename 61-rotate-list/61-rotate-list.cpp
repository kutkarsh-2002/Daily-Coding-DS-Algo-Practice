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
    
    ListNode* rotateRight(ListNode* head, int k) {
        /*if(head==NULL){
            return NULL;
        }
        else if(head->next==NULL){
            return head;
        }
        else{
            deque<int>dq;
            ListNode* curr=head;
            while(curr!=NULL){
                dq.push_back(curr->val);
                curr=curr->next;
            }
            
            while(k--){
                dq.push_front(dq.back());
                dq.pop_back();
            }
            
            head=NULL;
            curr=NULL;
            while(!dq.empty()){
                if(head==NULL){
                    ListNode* temp= new ListNode(dq.front());
                    head=temp;
                    curr=head;
                }else{
                    ListNode* temp= new ListNode(dq.front());
                    curr->next=temp;
                    curr=curr->next;
                }
                
                dq.pop_front();
            }
            curr->next=NULL;
        }
        
        return head;*/
        
        if(!head) return head;
        
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if(k %= len) 
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next; 
        tail->next = NULL;
        return newH;
    }
};