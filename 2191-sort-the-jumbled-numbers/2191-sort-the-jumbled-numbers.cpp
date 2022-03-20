class Solution {
public:
    long long mapped(int x, vector<int>&mapping){
        
        if(x<=9){
            return mapping[x];
        }
        
        long long ans=0;
        int power=1;
        while(x>0){
            
            int digit = x % 10;
            int mapped_digit = mapping[digit];
            ans += mapped_digit * power;
            power *= 10;
            x/=10;
        }
    cout<<ans<<endl;
        return ans;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int>res;
        vector<pair<int, int>>ans;
        
        for(int i=0; i<nums.size(); i++){
            int temp=mapped(nums[i], mapping);
            ans.push_back({temp, i});
            
        }
        
        sort(ans.begin(), ans.end(),
              [] (const auto &x, const auto &y) { return x.first < y.first; });
        
        for(auto x:ans){
            res.push_back(nums[x.second]);
        }
        
        return res;
    }
};