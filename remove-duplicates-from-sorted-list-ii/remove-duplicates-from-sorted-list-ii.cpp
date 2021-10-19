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
    ListNode* deleteDuplicates(ListNode* head) {
        
//         if(head==NULL){
//             return NULL;
//         }
//         if(head->next==NULL){
//             return head;
//         }
//         ListNode * curr=head->next, *prev=head;
        
//         while(curr!=NULL && prev->val==curr->val && prev!=NULL){
                
//                 ListNode* temp=prev;
//                 prev=curr->next;
//                 delete(curr);
//                 delete (temp);
//                 curr=prev->next;
                
//         }
//         head=prev;
//         while(curr!=NULL && prev!=NULL){
//             if(prev->val != curr->val){
//                 prev=prev->next;
//                 curr=curr->next;
//             }
//            else if(prev->val == curr->val){
//                 ListNode* temp=prev;
//                 prev=curr->next;
//                 delete(curr);
//                 delete (temp);
//                 curr=prev->next;
//             }
            
//         }
        
//         return head;
        
        ListNode* curr=head;
        head=NULL;
        
        map<int, int>mp;
        while(curr!=NULL){
            mp[curr->val]++;
            curr=curr->next;
        }
        
        for(auto x: mp){
            if(x.second==1 && head==NULL){
                ListNode* temp=new ListNode(x.first);
                head=temp;
                curr=head;
            }
            else if(x.second==1){
                ListNode* temp=new ListNode(x.first);
                curr->next=temp;
                curr=curr->next;
            }
        }
        
        return head;
    }
};