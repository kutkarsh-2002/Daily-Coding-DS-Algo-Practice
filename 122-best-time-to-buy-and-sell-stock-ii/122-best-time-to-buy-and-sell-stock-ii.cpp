class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
//         int n=prices.size();
//         vector<vector<int>>dp(n+1, vector<int>(2, -1));
        
//         dp[n][0]=0, dp[n][1]=0;
        
//         for(int i=n-1; i>=0; i--){
            
//             int profit=0;
            
//             for(int buy=0; buy<=1; buy++){
//                 if(buy){
        
//                     profit=max(-prices[i]+dp[i+1][0], dp[i+1][1]);
//                  }
//                 else{
        
//                     profit=max(prices[i]+dp[i+1][1], dp[i+1][0]);
//             }
                
//             dp[i][buy]=profit;
                
//             }
          
//         }
        
        
//         return dp[0][1];
        
        /* Space Optimization */
        
        int n=prices.size();
        vector<int>ahead(2, 0);
        ahead[0]=0, ahead[1]=0;
        
        for(int i=n-1; i>=0; i--){
            
            int profit=0;
            
            for(int buy=0; buy<=1; buy++){
                if(buy){
        
                    profit=max(-prices[i]+ahead[0], ahead[1]);
                 }
                else{
        
                    profit=max(prices[i]+ahead[1], ahead[0]);
            }
                
            ahead[buy]=profit;
                
            }
          
        }
        
        
        return ahead[1];
    }
};