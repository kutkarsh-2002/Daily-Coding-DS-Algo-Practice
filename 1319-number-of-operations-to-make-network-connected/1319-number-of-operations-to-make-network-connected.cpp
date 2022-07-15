class Solution {
public:
    int findParent(int node, vector<int>&parent){
        if(node==parent[node])
            return node;
        
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
        }
        else{
            parent[v]=u;
            rank[u]++;
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int>rank(n, 0);
        vector<int>parent(n);
        
        for(int i=0; i<n; i++){
            parent[i]=i;
        }
        
        for(int i=0; i<connections.size(); i++){
            if(findParent(connections[i][0], parent)!=findParent(connections[i][1], parent)){
                unionset(connections[i][0], connections[i][1], rank, parent);
            }
        }
        
        int count=0;
        
        for(int i=0; i<n; i++){
            if(parent[i]==i)count++;
        }
        
        return count-1;
    }
};