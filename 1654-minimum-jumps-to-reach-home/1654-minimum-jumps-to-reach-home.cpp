class Solution {
public:
    
    
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int>st(forbidden.begin(), forbidden.end());
        
        //1->backward, 0->forward
        
        queue<pair<int, int>>q;
        q.push({0, 0});
        int ans=0;
        
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto curr=q.front();
                q.pop();
                
                if(curr.first==x)return ans;
                
                if(st.find(curr.first)!=st.end()) continue;
                
                st.insert(curr.first);
                
                if(curr.second==0 && curr.first-b>=0){
                    q.push({curr.first-b, 1});
                }
                
                if(curr.first<=2000+b){
                    q.push({curr.first+a, 0});
                }
            }
            ans++;
        }
        
        return -1;
        
        
    }
};