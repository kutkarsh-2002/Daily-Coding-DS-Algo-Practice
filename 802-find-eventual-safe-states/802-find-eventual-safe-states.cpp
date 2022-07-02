class Solution {
public:
    
    bool dfs(int u, vector<int>&vis, vector<vector<int>>& graph){
        vis[u]=1;
        
        for(auto curr:graph[u]){
            if((vis[curr]==0 && dfs(curr, vis, graph)) || vis[curr]==1)
                return true;
        }
        
        vis[u]=2;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        vector<int>vis(graph.size()), res;
        
        for(int i=0; i<graph.size(); i++){
            if(vis[i]==2 || !dfs(i, vis, graph)){
                res.push_back(i);
            }
        }
        
        return res;
    }
};