class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int>v;
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        
        return v;
    }
};