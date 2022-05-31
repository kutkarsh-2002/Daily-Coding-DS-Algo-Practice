class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
//         int n=prices.size();
//         vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
        
//         for(int i=n; i>=0; i--){
//             for(int buy=0; buy<=1; buy++){
//                 dp[i][buy][0]=0;
//             }
//         }
        
        
//         for(int buy=0; buy<=1; buy++){
//               for(int cap=0; cap<=2; cap++){
//                   dp[n][buy][cap]=0;
//               }  
//         }
        
//         for(int i=n-1; i>=0; i--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int cap=1; cap<=2; cap++){
//                     int profit=0;
    
//                     if(buy){
//                         profit=max(-prices[i]+dp[i+1][0][cap], dp[i+1][1][cap]);
//                     }
//                     else{
//                         profit=max(prices[i]+dp[i+1][1][cap-1], dp[i+1][0][cap]);
//                     }
                    
//                     dp[i][buy][cap]=profit;
                    
//                 }
//             }
//         }
        
//         return dp[0][1][2];
        
        /*space optimization */
        
        int n=prices.size();
        vector<vector<int>>after(2, vector<int>(3, 0));
        vector<vector<int>>curr(2, vector<int>(3, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
                    int profit=0;
    
                    if(buy){
                        profit=max(-prices[i]+curr[0][cap], curr[1][cap]);
                    }
                    else{
                        profit=max(prices[i]+curr[1][cap-1], curr[0][cap]);
                    }
                    
                    curr[buy][cap]=profit;
                    
                }
            }
            
            after=curr;
        }
        
        return after[1][2];
        
    }
};