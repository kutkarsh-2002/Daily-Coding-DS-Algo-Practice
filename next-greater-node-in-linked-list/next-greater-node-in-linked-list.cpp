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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;
        stack<int>s;
        vector<int>v2;
        ListNode* curr=head;
        while(curr!=NULL){
            v2.push_back(curr->val);
            curr=curr->next;
        }
        int n=v2.size();
        for(int i=n-1; i>=0; i--){
            while(s.empty()==false && s.top()<=v2[i]){
                s.pop();
            }
            int res=(s.empty())?0:s.top();
            v.push_back(res);
            s.push(v2[i]);
        }
        reverse(v.begin(), v.end());
        return v;
        
        
    }
};