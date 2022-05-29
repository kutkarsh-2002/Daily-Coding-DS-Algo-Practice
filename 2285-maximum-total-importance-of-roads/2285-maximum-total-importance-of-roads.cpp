class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& a) {
        
        
        vector<int>v(n, 0);
        
        for(int i=0; i<a.size(); i++){
            v[a[i][0]]++;
            v[a[i][1]]++;
        }
        
        vector<pair<int, int>>temp;
        
        for(int i=0; i<v.size(); i++){
            temp.push_back({v[i], i});
        }
        
        sort(temp.begin(), temp.end());
        
        
        
        v.clear();
        int j=1;
        
        for(auto x: temp){
            v[x.second]=j;
            //cout<<x.second<<" "<<v[x.second]<<endl;
            j++;
        }
        
        
        long long ans=0;
        
        for (int i = 0; i < a.size(); i++)
        {
                long long sum=0;
            for (int j = 0; j < a[i].size(); j++)
            {   
                sum+=v[a[i][j]];
                
            }
            
            
            ans+=sum;
        }
        
        return ans;
        
    }
};