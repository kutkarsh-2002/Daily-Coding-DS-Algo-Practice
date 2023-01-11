// class Solution {
// public:
//     int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
//     }
// };

class Solution {
public:
    int dfs(vector<vector<int>> &graph,vector<bool> &hasApple,int n,vector<bool> &vis){
        // Mark the node visited
        vis[n] = 1;
        int t = 0; // time taken from this node to collect downward apples
        for(int node : graph[n]){
            if(!vis[node])
                t+=dfs(graph,hasApple,node,vis);
        }
        if(hasApple[n] or t>0) return t+2; // if any of the child or the node will have apple than we will add 2 sec.
        else return 0;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> graph(n);
        vector<bool> vis(n);
        for(vector<int> edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        int time = 0;
        vis[0] = true;
        for(int n : graph[0])
            if(!vis[n])
                time+=dfs(graph,hasApple,n,vis);
        return time;
    }
};