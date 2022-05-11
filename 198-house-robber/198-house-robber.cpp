class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        if(nums.size()==1){
            return nums[0];
        }
        
        if(nums.size()==2){
            return max(nums[0], nums[1]);
        }
        
        int n=nums.size();
        int dp[n];
        
        dp[0]=nums[0];
        dp[1]=nums[1];
        dp[2]=max(nums[0]+nums[2], nums[1]);
        
        for(int i=3; i<nums.size(); i++){
            dp[i]=max(max(dp[i-2], dp[i-3])+nums[i], dp[i-1]);
        }
        
        return max(dp[n-1], dp[n-2]);
    }
};