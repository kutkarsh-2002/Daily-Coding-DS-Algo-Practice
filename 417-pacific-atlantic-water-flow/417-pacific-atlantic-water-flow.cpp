class Solution {
public:
    void dfs(int i, int j, vector<vector<bool>>&vis, vector<vector<int>>& h){
        vis[i][j]=true;
        
        if(i-1>=0 && vis[i-1][j]!=true && h[i-1][j]>=h[i][j]){
            dfs(i-1, j, vis, h);
        }
        
        if(j-1>=0 && vis[i][j-1]!=true && h[i][j-1]>=h[i][j]){
            dfs(i, j-1, vis, h);
        }
        
        if(j+1<h[0].size() && vis[i][j+1]!=true && h[i][j+1]>=h[i][j]){
            dfs(i, j+1, vis, h);
        }
        
        if(i+1<h.size() && vis[i+1][j]!=true && h[i+1][j]>=h[i][j]){
            dfs(i+1, j, vis, h);
        }
        
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        
        int m=h.size(), n=h[0].size();
        
        vector<vector<bool>>pacific(m, vector<bool>(n));
        vector<vector<bool>>atlantic(m, vector<bool>(n));
        
        
        vector<vector<int>>res;
        
        for(int i=0; i<m; i++){
            dfs(i, 0, pacific, h);
            dfs(i, n-1, atlantic, h);
        }
        
        for(int j=0; j<n; j++){
            dfs(0, j, pacific, h);
            dfs(m-1, j, atlantic, h);
        }
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        
        return res;
    }
};


