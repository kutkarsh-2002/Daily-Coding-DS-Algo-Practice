class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
//         queue<pair<int, int>>q;
//         vector<int>dir{0, 1, 0, -1, 0};
//         for(int i=0; i<mat.size(); i++){
//             for(int j=0; j<mat[0].size(); j++){
//                 if(mat[i][j]==0){
//                     q.push({i, j});
//                 }else{
//                     mat[i][j]=-1;
//                 }
//             }
//         }
        
//         while(!q.empty()){
//             int r=q.front().first;
//             int c=q.front().second;
            
//             for(int i=0; i<4; i++){
//                 int nr=r+dir[i], nc=c+dir[i+1];
                
//                 if(nr<0 || nc<0 || nr>=mat.size() || nc>=mat[0].size() || mat[nr][nc]!=-1) continue;
                
//                 mat[nr][nc]=mat[r][c]+1;
//                 q.push({nr, nc});
//             }
//         }
        
        
//         return mat;
        
        int m=mat.size(), n=mat[0].size(), INF=m+n;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                
                if(mat[i][j]==0) continue;
                int top = INF, left = INF;
                
                if(i-1>=0)
                    top=mat[i-1][j];
                if(j-1>=0)
                    left=mat[i][j-1];
                
                mat[i][j]=min(top, left)+1;
            }
        }
        
        
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                
                if(mat[i][j]==0) continue;
                int bottom = INF, right = INF;
                if(i+1<m) bottom=mat[i+1][j];
                if(j+1<n) right=mat[i][j+1];
                
                mat[i][j]=min(mat[i][j], min(bottom, right)+1);
            }
        }
        
        return mat;
    }
};