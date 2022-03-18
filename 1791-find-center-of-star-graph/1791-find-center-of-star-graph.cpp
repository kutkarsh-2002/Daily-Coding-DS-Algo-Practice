class Solution {
public:
    
    int findCenter(vector<vector<int>>& edges) {
        
        vector<vector<int>>v(edges.size()+2);
        
        for(auto it:edges){
            v[it[0]].push_back(it[1]);
            v[it[1]].push_back(it[0]);  
        }
        
        vector<int>fq(edges.size()+2, 0);
        vector<bool>visited(edges.size()+2, false);
        queue<int>q;
        q.push(1);
        visited[1]=true;
        
        while(!q.empty()){
            int tp=q.front();
            q.pop();
            for(auto x:v[tp]){
                if(visited[x]==false){
                    visited[x]=true;
                    q.push(x);
                    fq[x]++;
                    fq[tp]++;
                }
            }
        }
        
        int maxf=0, vertice=-1;
        
        for(int i=1; i<fq.size(); i++){
            if(fq[i]>maxf){
                maxf=fq[i];
                vertice=i;
            }
        }
        
        return vertice;
    }
};