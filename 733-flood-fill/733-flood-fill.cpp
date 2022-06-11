class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int col, int nCol, vector<vector<int>>&mat){
        if(i<0 || i>=image.size() || j<0 || j>=image[0].size() || image[i][j]!=col || mat[i][j]==1)
            return ;
        
        image[i][j]=nCol;
        mat[i][j]=1;
        
        dfs(image, i-1, j, col, nCol, mat);
        dfs(image, i, j+1, col, nCol, mat);
        dfs(image, i, j-1, col, nCol, mat);
        dfs(image, i+1, j, col, nCol, mat);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int nCol) {
        int col=image[sr][sc];
        vector<vector<int>>mat(image.size(), vector<int>(image[0].size(), 0));
        dfs(image, sr, sc, col, nCol, mat);
        return image;
    }
};