class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n=prices.size();
        vector<vector<int>>after(2, vector<int>(k+1, 0));
        vector<vector<int>>curr(2, vector<int>(k+1, 0));
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy){
                        curr[buy][cap]=max(-prices[i]+curr[0][cap], curr[1][cap]);
                    }else{
                        curr[buy][cap]=max(prices[i]+curr[1][cap-1], curr[0][cap]);
                    }
                }
            }
            
            after=curr;
        }
        
        return after[1][k];
    }
};