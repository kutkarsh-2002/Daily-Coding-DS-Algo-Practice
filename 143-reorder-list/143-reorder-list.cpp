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
    void reorderList(ListNode* head) {
        if(head->next==NULL){
            return ;
        }else if(head->next->next==NULL){
            return;
        }
        
        ListNode* curr=head;
        
        vector<ListNode*>v;
        
        while(curr!=NULL){
            v.push_back(curr);
            curr=curr->next;
        }
        
        int i=0, j=v.size()-1;
        head=NULL, curr=NULL;
        bool flag=true;
        
        while(i<=j){
            if(head==NULL){
                head=v[i];
                curr=head;
                flag=false;
                i++;
            }
            else if(head!=NULL && flag==false){
                
                curr->next=v[j];
                curr=curr->next;
                flag=true;
                j--;
            }
            else{
                curr->next=v[i];
                curr=curr->next;
                flag=false;
                i++;
            }
        }
        curr->next=NULL;
        
    }
};