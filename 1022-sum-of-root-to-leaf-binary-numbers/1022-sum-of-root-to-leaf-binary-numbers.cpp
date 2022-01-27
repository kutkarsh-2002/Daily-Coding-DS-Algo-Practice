/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int binaryToDecimal(string n)
{
    string num = n;
    int dec_value = 0;
 
    // Initializing base value to 1, i.e 2^0
    int base = 1;
 
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
 
    return dec_value;
}
    void solve(TreeNode* root, string temp, int & sum){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL && root->right==NULL){
            temp+=to_string(root->val);
            sum+=binaryToDecimal(temp);
            //cout<<sum<<endl;
            return ;
        }
        temp+=to_string(root->val);
        cout<<temp<<endl;
        solve(root->left, temp, sum);
        solve(root->right, temp, sum);
    }
    int sumRootToLeaf(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        
        int sum=0;
        string temp="";
        solve(root, temp, sum);
        return sum;
    }
};