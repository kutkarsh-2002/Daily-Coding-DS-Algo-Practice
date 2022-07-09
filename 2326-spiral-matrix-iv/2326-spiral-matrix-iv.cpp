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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>>mat(m, vector<int>(n, -1));
        int top=0, bottom=m-1, left=0, right=n-1;
        ListNode* curr=head;
        
        while(curr!=NULL && top<=bottom && left<=right){
            
            for(int j=left; j<=right && curr!=NULL; j++){
                mat[top][j]=curr->val;
                curr=curr->next;
            }
            
            top++;
            
            for(int i=top; i<=bottom && curr!=NULL; i++){
                mat[i][right]=curr->val;
                curr=curr->next;
            }
            right--;
            
            for(int j=right; j>=left && curr!=NULL; j--){
                mat[bottom][j]=curr->val;
                curr=curr->next;
            }
            
            bottom--;
            
            for(int i=bottom; i>=top && curr!=NULL; i--){
                mat[i][left]=curr->val;
                curr=curr->next;
            }
            left++;
            
        }
        
        return mat;
    }
};