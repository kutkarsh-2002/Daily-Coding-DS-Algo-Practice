class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        if(prices.size()==0){
            return {};
        }
        
        if(prices.size()==1){
            return {prices[0]};
        }
        
        
        int n=prices.size();
        stack<int>st;
        vector<int>res;
        
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && st.top()>prices[i]){
                st.pop();
            }
            
            int temp=(st.empty()==true)?0:st.top();
            res.push_back(prices[i]-temp);
            st.push(prices[i]);
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};