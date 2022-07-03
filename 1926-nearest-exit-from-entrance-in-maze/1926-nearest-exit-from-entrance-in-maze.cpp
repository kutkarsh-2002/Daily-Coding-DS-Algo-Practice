class Solution {
public:
    
    vector<int>dir{0, -1, 0, 1, 0};
    
    // int dx[4] = {0,-1,0,1};
    // int dy[4] = {-1,0,1,0};
    
    bool validate(int i, int j, vector<vector<int>>&vis, vector<vector<char>>&maze){
        if(i>=0 && j>=0 && i<maze.size() && j<maze[0].size() && maze[i][j]!='+' && vis[i][j]!=1){
            return true;
        }
        
        return false;
    }
    
    bool isExist(int x, int y, int st, int en, vector<vector<char>>& maze){
        if(x==st && y==en) return false;
        
        if((x==0 || x==maze.size()-1 || y==0 || y==maze[0].size()-1) && maze[x][y]!='+') return true;
        
        return false;
    }
    
    int bfs(int st, int en, vector<vector<int>>& vis, vector<vector<char>>& maze){
        queue<pair<int, pair<int, int>>>q;
        q.push({0, {st, en}});
        vis[st][en]=1;
        
        while(!q.empty()){
            
            int dis=q.front().first;
            int x=q.front().second.first;
            int y=q.front().second.second;
            q.pop();
            
            if(isExist(x, y, st, en, maze)){
                return dis;
            }
            
        
            
            for(int i=0; i<4; i++){
                int nx=x+dir[i], ny=y+dir[i+1];
                
                
                if(validate(nx, ny, vis, maze)){
                    q.push({dis+1, {nx, ny}});
                    vis[nx][ny]=1;
                }
                
            }
            
        }
        
        return -1;
    }
    
    
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        vector<vector<int>>vis(maze.size(), vector<int>(maze[0].size(), 0));
        
        return bfs(entrance[0], entrance[1], vis, maze);
        
    }
};

