class Solution {
public:
    
    
    
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int>deg(n, 0);
        
        for(int i=0; i<roads.size(); i++){
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
        }
        
        set<vector<int>>st(roads.begin(), roads.end());
        int res=0;
      
        
        for(int i=0; i<n; i++){
            
            for(int j=i+1; j<n; j++){
                int sum=deg[i]+deg[j];
                if(st.find({i, j})!=st.end() || st.find({j, i})!=st.end()) sum--;
                
                res=max(res, sum);
            }
            
        }
        
        return res;
        
    }
};