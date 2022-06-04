class Solution {
public:
    int mxSum(int i, int k, int n, vector<int>& arr, vector<int>&dp){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int maxAns=INT_MIN, mxel=INT_MIN, len=0;
        
        for(int j=i; j<min(n, i+k); j++){
            len++;
            mxel=max(mxel, arr[j]);
            int sum=len*mxel+mxSum(j+1, k, n, arr, dp);
            
            maxAns=max(maxAns, sum);
        }
        
        return dp[i]=maxAns;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        // vector<int>dp(n, -1);
        // return mxSum(0, k, n, arr, dp);
        
        vector<int>dp(n+1, 0);
        
        for(int i=n-1; i>=0; i--){
            int len=0, mxel=INT_MIN, mxAns=INT_MIN;
            for(int j=i; j<min(n, i+k); j++){
                len++;
                mxel=max(mxel, arr[j]);
                int sum=len*mxel+dp[j+1];
                mxAns=max(mxAns, sum);
            }
            
            dp[i]=mxAns;
        }
        
        return dp[0];
    }
};