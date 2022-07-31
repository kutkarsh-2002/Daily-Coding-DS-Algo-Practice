class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int>st(nums.begin(), nums.end());
        
        return st.size()-st.count(0);
    }
};