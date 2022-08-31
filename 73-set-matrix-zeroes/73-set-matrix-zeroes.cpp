class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>>q;
        
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            
            for(int i=x; i>=0; i--){
                matrix[i][y]=0;
            }
            
            for(int i=x; i<matrix.size(); i++){
                matrix[i][y]=0;
            }
            
            for(int j=y; j>=0; j--){
                matrix[x][j]=0;
            }
            
            for(int j=y; j<matrix[0].size(); j++){
                matrix[x][j]=0;
            }
            
        }
    }
};