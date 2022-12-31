class Solution {
public:
    void dfs(int u, int dst, vector<int>&v, vector<vector<int>>&res, vector<vector<int>>& graph){
       
        v.push_back(u);
        
        if(u==dst){
           res.push_back(v);
           v.pop_back();
           return ;
       }
        
        for(auto x: graph[u]){
            dfs(x, dst, v, res, graph);
            
        }
        
        v.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>>res;
        vector<int>v;
        int n=graph.size();
        
        dfs(0, n-1, v, res, graph);
        return res;
    }
};