class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int>st;
        int col=0, n=matrix.size();
        for(int i=0; i<n; i++){
            
            for(int j=0; j<n; j++){
                if(matrix[i][j]>=1 && matrix[i][j]<=n){
                    st.insert(matrix[i][j]);
                }
            }
            if(st.size()!=n)
                return false;
            
            st.clear();
            
            for(int k=0; k<n; k++){
                if(matrix[k][col]>=1 && matrix[k][col]<=n){
                    st.insert(matrix[k][col]);
                }
            }
            
            if(st.size()!=n)
                return false;
            
            st.clear();
            col=i+1;
        }
        
        return true;
    }
};