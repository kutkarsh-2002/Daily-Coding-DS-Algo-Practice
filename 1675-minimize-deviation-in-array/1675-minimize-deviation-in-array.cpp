class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int mx=INT_MIN, mn=INT_MAX;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]%2!=0)
                nums[i]=nums[i]*2;
            mn=min(mn, nums[i]);
            mx=max(mx, nums[i]);
        }
        
        int min_deviation=mx-mn;
        
        priority_queue<int>pq;
        
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        
        while((pq.top())%2==0){
            int top=pq.top();
            pq.pop();
            min_deviation=min(min_deviation, top-mn);
            top/=2;
            mn=min(mn, top);
            pq.push(top);
        }
        
        min_deviation=min(min_deviation, pq.top()-mn);
        
        return min_deviation;
    }
};