class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxp=0;
        int curr=prices[0];
        for(int i=1; i<prices.size(); i++){
            if(curr>prices[i])
                curr=prices[i];
            
            if(prices[i]-curr>maxp)
                maxp=prices[i]-curr;
        }
        
        return maxp;
    }
};