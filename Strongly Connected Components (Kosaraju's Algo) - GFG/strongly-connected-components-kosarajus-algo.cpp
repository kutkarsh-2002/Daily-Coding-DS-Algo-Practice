// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void revDFS(int node, vector<bool>&vis, vector<vector<int>>&transpose){
	    vis[node]=true;
	    for(auto x: transpose[node]){
	        if(vis[x]==false){
	            revDFS(x,vis,transpose);
	        }
	    }
	}
	void TopologicalSort(int s, stack<int>&st, vector<bool>&vis, vector<int> adj[]){
	    
	    vis[s]=true;
	    
	    for(auto x: adj[s]){
	        if(vis[x]==false){
	            TopologicalSort(x,st,vis,adj);
	        }
	    }
	    
	    st.push(s);
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int>st;
        vector<bool>vis(V, false);
        int count=0;
        
        for(int i=0; i<V; i++){
            if(vis[i]==false){
                TopologicalSort(i, st, vis, adj);
            }
        }
        
        vector<vector<int>>transpose(V); //Reversing a graph
        
        for(int i=0; i<V; i++){
            vis[i]=false;
            
            for(auto x: adj[i]){
                transpose[x].push_back(i);
            }
        }
        
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(vis[node]==false){
                revDFS(node, vis, transpose);
                count++;
            }
        }
        
        return count;
        
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends