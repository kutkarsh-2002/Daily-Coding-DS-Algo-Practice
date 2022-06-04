class Solution {
public:
    int mxColl(int i, int j, vector<int>& nums, vector<vector<int>>&dp){
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int maxi=INT_MIN;
        for(int ind=i; ind<=j; ind++){
            int cost=nums[i-1]*nums[ind]*nums[j+1]+mxColl(i, ind-1, nums, dp)+mxColl(ind+1, j, nums, dp);
            maxi=max(maxi, cost);
        }
        
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int c=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        vector<vector<int>>dp(c+2, vector<int>(c+2, -1));
        
        return mxColl(1, c, nums, dp);
    }
};