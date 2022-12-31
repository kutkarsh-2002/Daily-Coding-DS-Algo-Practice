// class Solution {
// public:
//     int uniquePathsIII(vector<vector<int>>& grid) {
        
//     }
// };

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& G) {
        int startRow, startCol, mask = 0;
        m = size(G), n = size(G[0]);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                if(G[i][j] == 1) startRow = i, startCol = j;
                if(G[i][j] != -1) mask |= 1 << i*n+j;       // set bits of cells that need to be visited
            }

        dfs(G, startRow, startCol, mask);
        return ans;
    }
private:
    int m, n, ans = 0, dir[5] {0, 1, 0, -1, 0}; 
    bool isValidCell(vector<vector<int>>& G, int i, int j, int mask) {
        return i >= 0 && j >= 0 && i < size(G) && j < size(G[0]) && G[i][j] != -1 && mask & 1 << i*n+j;
    }
	
    void dfs(vector<vector<int>>& G, int i, int j, int mask) {
        if(not isValidCell(G, i, j, mask)) return;
        mask ^= 1 << i*n+j;                                  // mark as visited by unsetting bit
        if(G[i][j] == 2) {       
            if(!mask) ans++;                                 // valid path if all required cells are visited
            return;              
        }
        for(int k = 0; k < 4; k++)
            dfs(G, i + dir[k], j + dir[k+1], mask);
    }        
};