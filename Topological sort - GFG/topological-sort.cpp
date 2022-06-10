// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	/*****BFS(Kahn's)******/
	
	vector<int> topoSort(int V, vector<int> adj[]){
	    
	    //vector<int>vis(V, 0);
	    vector<int>indg(V, 0);
	    vector<int>res;
	    
	    // Find the indegree of every node
	    for(int i=0; i<V; i++){
	        for(auto x: adj[i]){
	            indg[x]++;
	        }
	    }
	    
	    queue<int>q;
	    for(int i=0; i<indg.size(); i++){
	        if(indg[i]==0){
	            q.push(i);
	            
	        }
	    }
	    
	    while(!q.empty()){
	        int node=q.front();
	        res.push_back(node);
	        q.pop();
	        
	        for(auto x:adj[node]){
	            indg[x]-=1;
	            if(indg[x]==0){
	                q.push(x);
	            }
	        }
	    
	} 
	return res;
	}
	
	/*****************DFS*******/
	
// 	void TopologicalSort(int s, stack<int>&st, vector<bool>&vis, vector<int> adj[]){
	    
// 	    vis[s]=true;
	    
// 	    for(auto x: adj[s]){
// 	        if(vis[x]==false){
// 	            TopologicalSort(x,st,vis,adj);
// 	        }
// 	    }
	    
// 	    st.push(s);
// 	}
	
// 	vector<int> topoSort(int V, vector<int> adj[]) 
// 	{
// 	    stack<int>st;
//         vector<bool>vis(V, false);
//         vector<int>res;
        
//         for(int i=0; i<V; i++){
//             if(vis[i]==false){
//                 TopologicalSort(i, st, vis, adj);
//             }
//         }
        
//         while(!st.empty()){
//             res.push_back(st.top());
//             st.pop();
//         }
        
//         return res;
        
// 	}
	
	
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends