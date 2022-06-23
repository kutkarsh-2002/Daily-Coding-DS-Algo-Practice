class Solution {
public:
    void dfs(int i, int j, int &mni, int &mnj, int &mxi, int &mxj, vector<vector<int>>&vis, vector<vector<int>>&land){
        if(i<0 || j<0 || i>=land.size() || j>=land[0].size() || vis[i][j]==1 || land[i][j]==0){
            return ;
        }
        vis[i][j]=1;
        mni=min(mni, i);
        mnj=min(mnj, j);
        mxi=max(mxi, i);
        mxj=max(mxj, j);
        
        dfs(i-1, j, mni, mnj, mxi, mxj, vis, land);
        dfs(i, j-1, mni, mnj, mxi, mxj, vis, land);
        dfs(i, j+1, mni, mnj, mxi, mxj, vis, land);
        dfs(i+1, j, mni, mnj, mxi, mxj, vis, land);
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        
        vector<vector<int>>res;
        vector<vector<int>>vis(land.size(), vector<int>(land[0].size(), 0));
        
        int mni=INT_MAX, mnj=INT_MAX, mxi=INT_MIN, mxj=INT_MIN;
        
        for(int i=0; i<land.size(); i++){
            for(int j=0; j<land[0].size(); j++){
                if(land[i][j]==1 && vis[i][j]==0){
                    dfs(i, j, mni, mnj, mxi, mxj, vis, land);
                    vector<int>v;
                    v.push_back(mni);
                    v.push_back(mnj);
                    v.push_back(mxi);
                    v.push_back(mxj);
                    res.push_back(v);
                    mni=INT_MAX, mnj=INT_MAX, mxi=INT_MIN, mxj=INT_MIN;
                }
            }
        }
        
        return res;
    }
};