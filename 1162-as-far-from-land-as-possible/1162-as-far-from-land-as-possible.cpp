class Solution {
public:
vector<pair<int,int>>v={{1,0},{0,1},{-1,0},{0,-1}};
int maxDistance(vector<vector<int>>& grid) {

    int count=0;
    int n=grid.size();
    int m=grid[0].size();
    int g=0,c=0;
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({{i,j},0});
                c++;
            }
            else{
                count++;
            }
        }
    }
    if(c==n*m){
        return -1;
    }
    int res=0;
    while(!q.empty()){
            pair<pair<int,int>,int> x=q.front();
            q.pop();
            for(int i=0;i<v.size();i++){
                int z=v[i].first;
                int y=v[i].second;
                if(x.first.first+z>=0&&x.first.first+z<n&&x.first.second+y>=0&&x.first.second+y<m&&
                   grid[x.first.first+z][x.first.second+y]==0){
               grid[x.first.first+z][x.first.second+y]=1;
                    q.push({{x.first.first+z,x.first.second+y},x.second+1});
                }
        
    }
        g=x.second;
    }
    if(count==n*m){
        return -1;}
    
    return g;
}
};