class Solution {
public:
//     int LIS(int i, int prev, int n, vector<int>& nums, vector<vector<int>>&dp){
//         if(i==n) return 0;
        
//         if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        
//         int take=0;
//         if(prev==-1 || nums[prev]<nums[i]){
//             take=1+LIS(i+1, i, n, nums, dp);
//         }
        
//         int nottake=LIS(i+1, prev, n, nums, dp);
        
//         return dp[i][prev+1]=max(take, nottake);
//     }
    
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
//         vector<vector<int>>dp(n, vector<int>(n+1, -1));
        
//         return LIS(0, -1, n, nums, dp);
        
        /* Tabulation */
        
       
        vector<int>dp(n, 1);
        
        for(int i=0; i<n; i++){
            for(int prev=0; prev<i; prev++){
                
                if(nums[i]>nums[prev]){
                    dp[i]=max(dp[i], 1+dp[prev]);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};