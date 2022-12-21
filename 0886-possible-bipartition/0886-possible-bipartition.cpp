class Solution {
public:
    bool Bipartition(int u, int p, vector<int>&color, vector<int>adj[]){
        if(p==-1){
            color[u]=0;
        }else{
            color[u]=!color[p];
        }    
        
        for(auto v:adj[u]){
            if(color[v]==-1){
                
                if(!Bipartition(v, u, color, adj)) return false;
            }
            else if(color[v]!=-1 && color[v]==color[u]) return false;
            
        }
        
        return true;
    }
    
    
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        
        vector<int>adj[n+1];
        for(int i=0;i<dislikes.size();i++){
             adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int>color(n+1,-1);
        
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                if(!Bipartition(i, -1, color, adj)) return false;
            }
        }
        
        
        return true;
    }
    

    
};

