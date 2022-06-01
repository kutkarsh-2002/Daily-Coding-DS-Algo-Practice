class Solution {
public:
    
//     int maxprofit(int i, int buy, int n, vector<int>&prices, vector<vector<int>>&dp){
//         if(i>=n) return 0;
        
//         if(dp[i][buy]!=-1) return dp[i][buy];
        
//         if(buy){
//           return   dp[i][buy]=max(-prices[i]+maxprofit(i+1, 0, n, prices, dp), maxprofit(i+1, 1, n, prices, dp));
//         }
//         else
//           return   dp[i][buy]=max(prices[i]+maxprofit(i+2, 1, n, prices, dp), maxprofit(i+1, 0, n, prices, dp));
//     }
    
    int maxProfit(vector<int>& prices) {
        
        // int n=prices.size();
        // vector<vector<int>>dp(n, vector<int>(2, -1));
        // return maxprofit(0, 1, n, prices, dp);
        
        int n=prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2, -1));
        dp[n][0]=0, dp[n][1]=0, dp[n+1][0]=0, dp[n+1][1]=0;

        for(int i=n-1; i>=0; i--){


            for(int buy=0; buy<=1; buy++){
                if(buy){

                    dp[i][buy]=max(-prices[i]+dp[i+1][0], dp[i+1][1]);
                 }
                else{

                    dp[i][buy]=max(prices[i]+dp[i+2][1], dp[i+1][0]);
            }


            }

        }


        return dp[0][1];

    }
};