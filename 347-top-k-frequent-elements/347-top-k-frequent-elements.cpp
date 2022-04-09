class Solution {
public:
    struct myComp {
    constexpr bool operator()(
        pair<int, int> const& a,
        pair<int, int> const& b)
        const noexcept
    {
        return a.second < b.second;
    }
};
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int>mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myComp>pq;
        vector<int>res;
        
        for(int i=0; i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        for(auto x:mp){
            pq.push({x.first, x.second});
        }
        
        while(k>0){
            auto p=pq.top();
            res.push_back(p.first);
            pq.pop();
            k--;
        }
        
        return res;
        
        
    }
};