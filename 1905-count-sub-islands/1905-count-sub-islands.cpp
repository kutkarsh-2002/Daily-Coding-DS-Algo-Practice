class Solution {
public:
    
    void dfs1(int i, int j, vector<vector<int>>&vis, vector<vector<int>>&grid1, vector<vector<int>>&grid2){
        if(i<0 || i>=grid2.size() || j<0 || j>=grid2[0].size() || grid2[i][j]==0 || vis[i][j]==1){
            return ;
        }
        
        vis[i][j]=1;
        grid2[i][j]=0;

        
        dfs1(i-1, j, vis, grid1, grid2);
        dfs1(i, j-1, vis, grid1, grid2);
        dfs1(i, j+1, vis, grid1, grid2);
        dfs1(i+1, j, vis, grid1, grid2);
    }
    
    void dfs2(int i, int j, vector<vector<int>>&vis, vector<vector<int>>&grid1, vector<vector<int>>&grid2){
        if(i<0 || i>=grid2.size() || j<0 || j>=grid2[0].size() || grid2[i][j]==0 || grid1[i][j]==0 || vis[i][j]==1){
            return ;
        }
        
        vis[i][j]=1;
        //cout<<i<<" "<<j<<" ";
        
        dfs2(i-1, j, vis, grid1, grid2);
        dfs2(i, j-1, vis, grid1, grid2);
        dfs2(i, j+1, vis, grid1, grid2);
        dfs2(i+1, j, vis, grid1, grid2);
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        vector<vector<int>>vis(grid2.size(), vector<int>(grid2[0].size(), 0));
        
        int count=0;
        
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j]==1 && grid1[i][j]==0 && vis[i][j]==0){
                    dfs1(i, j, vis, grid1, grid2);
                
                }
            }
        }
        
        for(int i=0; i<grid2.size(); i++){
            for(int j=0; j<grid2[0].size(); j++){
                if(grid2[i][j]==1 && grid1[i][j]==1 && vis[i][j]==0){
                    dfs2(i, j, vis, grid1, grid2);
                    count++;
                }
            }
        }
        
        return count;
    }
};