class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        
        stack<pair<int, int>>st;
        vector<int>res;
        
        for(int i=temp.size()-1; i>=0; i--){
            
            while(st.empty()==false && st.top().second<=temp[i]){
                st.pop();
            }
            
            int val=(st.empty())?0:(st.top().first)-i;
            res.push_back(val);
            
            st.push({i, temp[i]});
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};