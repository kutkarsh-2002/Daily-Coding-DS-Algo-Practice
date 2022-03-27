class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int, int>>temp;
        vector<int>res;
        
        for(int i=0; i<mat.size(); i++){
            int count=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1){
                    count++;
                }
            }
            
            temp.push_back({count, i});
        }
        
        sort(temp.begin(), temp.end());
        
        for(int i=0; i<temp.size() && k>0; i++){
            auto x=temp[i];
            res.push_back(x.second);
            k--;
        }
        
        return res;
    }
};