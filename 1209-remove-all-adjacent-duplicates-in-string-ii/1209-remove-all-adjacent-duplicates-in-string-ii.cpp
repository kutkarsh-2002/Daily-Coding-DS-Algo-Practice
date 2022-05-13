class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>st;
        
        int n=s.size();
        
        if(n<k)
            return s;
        
        for(int i=0; i<n; i++){
            if(st.empty() || st.top().first!=s[i])
                st.push({s[i], 1});
            else{
                auto p=st.top();
                st.pop();
                st.push({s[i], p.second+1});
            }
            
            if(st.top().second==k)
                st.pop();
            
        }
        
        
        string ans="";
        
        while(!st.empty()){
            auto p=st.top();
            st.pop();
            
            while(p.second--){
                ans.push_back(p.first);
            }
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};