class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>res;
        res.push_back(nums[0]);
        
        for(int i=1; i<nums.size(); i++){
            while(!res.empty() && __gcd(res.back(), nums[i])>1){
                nums[i]=(nums[i])/__gcd(res.back(), nums[i]);
                nums[i]*=res.back();
                res.pop_back();
            }
            res.push_back(nums[i]);
        }
        return res;
    }
};