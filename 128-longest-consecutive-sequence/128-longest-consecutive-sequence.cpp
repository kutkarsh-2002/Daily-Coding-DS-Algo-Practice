class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        unordered_set<int>st;
        for(auto x:nums){
            st.insert(x);
        }
        
        int ans=1;
        
        for(int i=0; i<nums.size(); i++){
            if(st.find(nums[i]-1)==st.end()){
                int currnum=nums[i]+1;
                int count=1;

                while(st.find(currnum)!=st.end()){
                    count++;
                    currnum+=1;
                }

                ans=max(ans, count);
            }
        }
        
        return ans;
    }
};