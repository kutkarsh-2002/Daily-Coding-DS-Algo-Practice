class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1 || n==0)
            return 0;
        vector<int>dp(n, INT_MAX);
        
        dp[n-1]=0;
        
        for(int i=n-2; i>=0; i--){
            int res=INT_MAX;
            for(int j=i+1; j<=min(n-1, i+nums[i]); j++){
                res=min(res, dp[j]);
            }
            
            if(res!=INT_MAX){
                dp[i]=res+1;
            }
        }
        
        return dp[0];
        
        
    }
};