class Solution {
public:
    
    bool isValid(int i, int j, int &peri, vector<vector<int>>& vis, vector<vector<int>>& grid)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
        {   
            return false;
        }
        
        peri=peri-1;
        
        if(vis[i][j]==1)
            return false;
        
        return true;
    }
    
    void bfs(int i, int j, int &peri, vector<vector<int>>& vis, vector<vector<int>>& grid)
    {
        queue<pair<int, int>>q;
        q.push({i, j});
        vis[i][j]=1;
        
        while(!q.empty())
        {
            auto node=q.front();
            i=node.first, j=node.second;
            q.pop();
            peri+=4;
            
            if(isValid(i-1, j, peri, vis, grid)){
                q.push({i-1, j});
                vis[i-1][j]=1;
            }
            
            if(isValid(i, j-1, peri, vis, grid)){
                q.push({i, j-1});
                vis[i][j-1]=1;
            }
            
            if(isValid(i, j+1, peri, vis, grid)){
                q.push({i, j+1});
                vis[i][j+1]=1;
            }
            
            if(isValid(i+1, j, peri, vis, grid)){
                q.push({i+1, j});
                vis[i+1][j]=1;
            }
            cout<<peri<<" ";
        }
    }
    
    int bfs(int i, int j, int &count, vector<vector<int>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0)
         {   
            return 0;
         }
        
            return 1;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(), vector<int>(grid[0].size(), 0));
        int peri=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    bfs(i, j, peri, vis, grid);
                }
            }
        }
        
        // for(int i=0; i<grid.size(); i++){
        //     for(int j=0; j<grid[0].size(); j++){
        //         if(grid[i][j]==1){
        //             int count=0;
        //             count+=(bfs(i-1, j, count, grid)==0)?0:1;
        //             count+=(bfs(i, j-1, count, grid)==0)?0:1;
        //             count+=(bfs(i, j+1, count, grid)==0)?0:1;
        //             count+=(bfs(i+1, j, count, grid)==0)?0:1;
        //             peri+=(4-count);
        //         }
        //     }
        // }
        
        return peri;
    }
};