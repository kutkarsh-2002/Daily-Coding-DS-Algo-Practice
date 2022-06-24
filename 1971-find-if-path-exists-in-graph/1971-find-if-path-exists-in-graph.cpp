class Solution {
public:
    
//     bool dfs(int u, int dst, vector<int>&vis, vector<int>adj[]){
        
//         if(u==dst)
//             return true;
        
//         vis[u]=1;
        
        
//         for(auto v: adj[u]){
           
//             if(vis[v]==0){
//                 if(dfs(v, dst, vis, adj)) return true;
//             }
            
//         }
        
//         return false;
//     }
    
//     bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
//         vector<int>adj[n];
        
//         for(int i=0; i<edges.size(); i++){
//             adj[edges[i][0]].push_back(edges[i][1]);
//             adj[edges[i][1]].push_back(edges[i][0]);
//         }
        
//         vector<int>vis(n, 0);
        
//         return dfs(src, dst, vis, adj);
//     }
    
    
    int findParent(int node, vector<int>&parent){
        if(node==parent[node]){
            return node;
        }
        
        return parent[node]=findParent(parent[node], parent);
    }
    
    void unionset(int u, int v, vector<int>&rank, vector<int>&parent){
        u=findParent(u, parent);
        v=findParent(v, parent);
        
        if(rank[u]>rank[v]){
            parent[v]=u;
        }
        else if(rank[u]<rank[v]){
            parent[u]=v;
        }else{
            parent[v]=u;
            rank[u]++;
        }
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int src, int dst) {
    
        vector<int>rank(n, 0);
        vector<int>parent(n);
        
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        
        for(int i=0; i<edges.size(); i++){
            int u=edges[i][0];
            int v=edges[i][1];
            unionset(u, v, rank, parent);
        }
        
        cout<<findParent(src, parent)<<endl;
        cout<<findParent(dst, parent)<<endl;
        
        if(findParent(src, parent)==findParent(dst, parent))
            return true;
        
        return false;
    }
};