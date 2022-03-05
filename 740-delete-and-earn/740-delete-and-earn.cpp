class Solution {
public:
    
    int solve(int i,vector<int> &freq,vector<int> &dp){
        if(i >= dp.size()) return 0;
        else if(dp[i] != -1) return dp[i];
        
        int pick = 0;
        if(dp[i]) pick = (i*freq[i]) + solve(i+2,freq,dp);
        int not_pick = solve(i+1,freq,dp);
        
        int ans = max(pick,not_pick);
        return dp[i] = ans;
    }
    
    
    int deleteAndEarn(vector<int>& nums) {
        
        int size = *max_element(nums.begin(),nums.end());
        
        vector<int> freq(size+1),dp(size+1,-1);
        
        for(auto it : nums) freq[it]++;
		
        int ans = solve(1,freq,dp);
        
        return ans;
    }
};