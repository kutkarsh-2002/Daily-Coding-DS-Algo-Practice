class Solution {
public:
    
    /*For Finding the binomial coefficient
    Row=n, Column=K, res=1;
    
    for(int i=0; i<k; i++){
    res*=(n-i);
    res/=(i+1);
    }
    return res;
    */
    
    int binomialcf(int n, int k){
        int res=1;
        if(k==0){
            return res;
        }
        
        for(int i=0; i<k; i++){
            res*=(n-i);
            res/=(i+1);
        }
        
        return res;
        
    }
    vector<vector<int>> generate(int Rows) {
        vector<vector<int>>mat;
        if(Rows==0)
            return mat;
        
        for(int i=0; i<Rows; i++){
            vector<int>v;
            v.push_back(1);
            int col=i+1;
            for(int j=1; j<col; j++){
                v.push_back(binomialcf(i, j));
                
            }
            mat.push_back(v);
        }
        
        return mat;
    }
};