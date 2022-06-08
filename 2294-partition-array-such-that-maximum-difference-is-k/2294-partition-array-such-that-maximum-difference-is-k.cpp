class Solution {
public:
    
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int mx=INT_MIN, mi=INT_MAX;
        int res=1;
        
        for(int i=0; i<nums.size(); i++){
            mx=max(mx, nums[i]);
            mi=min(mi, nums[i]);
            if(mx-mi>k){
                res++;
                mx=nums[i];
                mi=nums[i];
            }
        }
        
        return res;
    }
};