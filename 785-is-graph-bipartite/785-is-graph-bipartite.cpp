class Solution {
public:
    bool bfsBip(int u, vector<int>&colr, vector<vector<int>>& graph){
        queue<int>q;
        q.push(u);
        colr[u]=0;
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            for(auto x:graph[node]){
                if(colr[x]==-1){
                    q.push(x);
                    colr[x]=!colr[node];
                }
                else if(colr[x]!=-1 && colr[x]==colr[node]) return false;
            }
        }
        
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>colr(n+1, -1);
        
        for(int i=0; i<n; i++){
            if(colr[i]==-1){
                if(bfsBip(i, colr, graph)==false) return false;
            }
        }
        
        return true;
    }
};