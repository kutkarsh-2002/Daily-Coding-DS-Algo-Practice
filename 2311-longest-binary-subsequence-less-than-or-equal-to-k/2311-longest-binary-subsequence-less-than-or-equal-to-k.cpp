class Solution {
public:
    
    int lbs(int i, int size, string&s, int sum, vector<vector<int>>&dp){
        if(i<0) return 0;
        
        if(dp[i][size]!=-1) return dp[i][size];
        
        int take=0;
        
        if((sum-(s[i]-'0')*pow(2, size))>=0){
            take=1+lbs(i-1, size+1, s, (sum-(s[i]-'0')*pow(2, size)), dp);
        }
        int nottake=0+lbs(i-1, size, s, sum, dp);
        
        return dp[i][size]=max(take, nottake);
        
    }
    
    int longestSubsequence(string s, int k) {
        
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n, -1));
        
        return lbs(n-1, 0, s, k, dp);
    }
};