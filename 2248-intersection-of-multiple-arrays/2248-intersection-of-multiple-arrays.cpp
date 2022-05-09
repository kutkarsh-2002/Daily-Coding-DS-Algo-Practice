class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        vector<int>ans;
        list<int>li;
        
        for(int j=0; j<nums[0].size(); j++){
            li.push_back(nums[0][j]);
        }
        
        for(int i=1; i<nums.size(); i++){
            unordered_set<int>st;
            for(int j=0; j<nums[i].size(); j++){
                st.insert(nums[i][j]);
            }
            
            list<int>temp(li);
            for(auto it=li.begin(); it!=li.end(); it++){
                if(st.find(*it)==st.end()){
                    temp.remove(*it);
                }
            }
            
            li.clear();
            li=temp;
            
        }
        
        for(auto it=li.begin(); it!=li.end(); it++){
                ans.push_back(*it);
            }
        
        
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};