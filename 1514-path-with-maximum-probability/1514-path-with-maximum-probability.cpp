class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sP, int s, int e) {
        
        vector<double>dis(n, 0);
        vector<vector<pair<int, double>>>graph(n);
        
        for(int i=0; i<edges.size(); i++){
            graph[edges[i][0]].push_back({edges[i][1], sP[i]});
            graph[edges[i][1]].push_back({edges[i][0], sP[i]});
        }
        
        priority_queue<pair<double, int>>pq;
        dis[s]=1;
        pq.push({1.0, s});
        
        while(!pq.empty())
        {
            double dis_so_far=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
           for(int j=0; j<graph[node].size(); j++){
               int v=graph[node][j].first;
               double wt=graph[node][j].second;
               
               if(dis[v]<wt*dis_so_far){
                   dis[v]=wt*dis_so_far;
                   pq.push({wt*dis_so_far, v});
               }
           }
        }
        
        return dis[e];
    }
};