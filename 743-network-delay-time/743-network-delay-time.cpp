class Solution {
public:
    
    void dfs(int u, vector<int>&vis, vector<vector<pair<int, int>>>&graph)
    {
        vis[u]=1;
        
        for(int j=0; j<graph[u].size(); j++){
            int v=graph[u][j].first;
            if(vis[v]==0){
                dfs(v, vis, graph);
            }
        }
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>vis(n+1, 0);
        vector<vector<pair<int, int>>>graph(n+1);
        
        for(int i=0; i<times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        dfs(k, vis, graph);
        
        for(int i=1; i<=n; i++){
            if(vis[i]!=1){
                return -1;
            }
        }
        
        vector<int>dis(n+1, INT_MAX);
        dis[k]=0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        
        pq.push({0, k});
        
        while(!pq.empty())
        {
            int node=pq.top().second;
            pq.pop();
            
            for(int j=0; j<graph[node].size(); j++){
                if(dis[graph[node][j].first]>graph[node][j].second +dis[node])
                {
                    dis[graph[node][j].first]=graph[node][j].second +dis[node];
                    pq.push({graph[node][j].second +dis[node], graph[node][j].first});
                }
            }
        }
        
        int ans=0;
        
        for(int i=1; i<=n; i++){
            ans=max(ans, dis[i]);
        }
        
        return ans;
        
    }
};