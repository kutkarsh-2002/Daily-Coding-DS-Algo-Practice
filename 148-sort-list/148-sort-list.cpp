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
    ListNode* sortList(ListNode* head) {
        
        ListNode* curr=head;
        vector<int>v;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        sort(v.begin(), v.end());
        
        head=NULL;
        
        for(int i=0; i<v.size(); i++){
            if(head==NULL){
                ListNode* temp=new ListNode(v[i]);
                head=temp;
                curr=head;
            }else{
                ListNode* temp=new ListNode(v[i]);
                curr->next=temp;
                curr=curr->next;
                
            }
        }
        
        return head;
    }
};