class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int>arr;
        for(int i=0; i<(nums.size())/2; i++){
            while(nums[2*i]--){
                arr.push_back(nums[2*i+1]);
            }
        }
        return arr;
        
        
    }
};