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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.size()==0){
            return NULL;
        }
        if(lists.size()==1){
            return lists[0];
        }
        vector<int>v;
        
        for(auto it: lists){
            ListNode* curr = it;
            while(curr){
                ListNode* temp = curr->next;
                curr->next = NULL;
                v.push_back(curr->val);
                curr = temp;
            }
        }
        
        
        sort(v.begin(), v.end());
        
        if(v.size()==0){
            return NULL;
        }
        
        ListNode* head=NULL, *curr=NULL;
        
        for(int i=0; i<v.size(); i++){
            
            if(head==NULL){
                ListNode* temp=new ListNode(v[i]);
                head=temp;
                curr=head;
                
            }
            else{
                ListNode* temp=new ListNode(v[i]);
                curr->next=temp;
                curr=curr->next;
            }
        }
       curr->next=NULL;
        return head;
        
        
       
        
        
    }
};