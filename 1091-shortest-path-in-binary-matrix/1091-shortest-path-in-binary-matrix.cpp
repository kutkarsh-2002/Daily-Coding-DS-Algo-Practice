 #define pii pair<int, pair<int, int>>
class Solution {
public:
   
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
        int row = grid.size();
        if (row == 0) return -1;
        int col = grid[0].size();
        if (col == 0 ) return -1;
        if (grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;

        //queue<pair<int, int>> queue;
        priority_queue<pii, vector<pii>, greater<pii>>pq; 
        //queue.push(make_pair(0,0));
        
        pq.push({1, {0, 0}});
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        grid[0][0] = 1;
        while(!pq.empty()){
            //auto curr = queue.front();
            auto curr=pq.top();
            int x = curr.second.first, y = curr.second.second, dis=curr.first;
            if( x == row -1 && y == col -1) return grid[x][y];

            for(auto direction : directions){
                int nx = x + direction[0];
                int ny = y + direction[1];
                if(nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] == 0){
                    //queue.push(make_pair(nx,ny));
                    pq.push({dis+1, {nx, ny}});
                    grid[nx][ny] = dis + 1;
                }
            }
            pq.pop();
        }
        return -1;
    }
};