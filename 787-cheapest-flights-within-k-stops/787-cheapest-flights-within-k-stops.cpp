#define pii pair<int, pair<int, int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     
        vector<vector<pair<int, int>>>graph(n);
        
        for(int i=0; i<flights.size(); i++){
            graph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        
        
        vector<int>vis(n,INT_MAX);
        
        priority_queue<pii, vector<pii>, greater<pii>>pq;
        
        pq.push({0, {src, 0}});
        
        while(!pq.empty()){
            int u=pq.top().second.first;
            int cst=pq.top().first;
            int cur_edge=pq.top().second.second;
            pq.pop();
            
            if(u==dst){
                return cst;
            }
            
            if(cur_edge>k) continue;
            
            
            if(vis[u]!=INT_MAX && vis[u]<cur_edge) continue;
            
            vis[u]=cur_edge;
                
            for(auto v:graph[u]){
                pq.push({cst+v.second, {v.first, cur_edge+1}});
            }
            
        }
        
        return -1;
        
        
    }
};


