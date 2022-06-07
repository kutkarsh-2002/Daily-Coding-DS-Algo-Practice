class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        while(k--){
            int mini=min_element(nums.begin(), nums.end())-nums.begin();
            nums[mini]=-(nums[mini]);
        }
        
        int sum=0;
        for(int i=0; i<nums.size(); i++){
            sum+=nums[i];
        }
        
        return sum;
    }
};