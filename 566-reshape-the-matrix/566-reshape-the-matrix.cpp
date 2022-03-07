class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        if(mat.size()==r && mat[0].size()==c)
            return mat;
        
        int n=mat.size(), m=mat[0].size();
        int total=n*m;
        
        if((r*c)!=total)
            return mat;
        
        
        //i*m+j is the index in 1-d array where value of mat[i][j] will be stored.
        //m=no. of cols, n=no. of rows
        //v[i*m+j]=mat[i][j];
           
        
        vector<vector<int>>res(r, vector<int>(c,0));
        
        
        for(int i=0; i<total; i++){
            res[i/c][i%c]=mat[i/m][i%m];
        }
        
        return res;
    }
};