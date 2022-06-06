/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        unordered_set<ListNode*>s;
        
        ListNode* currA=headA;
        
        while(currA!=NULL){
            s.insert(currA);
            currA=currA->next;
        }
        
        ListNode* currB=headB;
        while(currB!=NULL){
            if(s.find(currB)!=s.end()){
                return currB;
            }else{
                currB=currB->next;
            }
        }
        return NULL;
    }
};