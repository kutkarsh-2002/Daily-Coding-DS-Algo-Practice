class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int pairs=0;
        int i,j;
        for(i=0; i<nums.size()-1; i++)
        {
            for(j=i+1; j<nums.size(); j++)
            {
                if(nums[i]==nums[j])
                {
                    pairs++;
}
}
            
        }
        return pairs;
        
    }
};