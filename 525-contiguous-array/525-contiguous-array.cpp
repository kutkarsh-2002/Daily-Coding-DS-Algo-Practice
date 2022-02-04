class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        
        nums.insert(nums.begin(), 0);     //this will insert 0 in begining which will make vector 1 indexing.   
        
        //Unorder_map will help to store prefix sum as a key and index as value to analyze if same key repeats then there must be chance that combination of equal 1's & 0's.
        
        unordered_map<int, int>mp;
        int length=0;
        //prefix_sum(Generally prefix sum concepts help to solve range related problems)
        
        
        int sum=1;
        mp[sum]=0;
        
        for(int i=1; i<nums.size(); i++){
            
            //Replace all the 0 value with -1
        //so that sum with equal combination of 1 & 0 result to 0.
            nums[i]=(nums[i]==0)?-1:1;
            sum+=nums[i];
            
            if(mp.find(sum)!=mp.end()){
                //If sum repeats the there must be equal 1 & 0 in the range.
                length=max(length, i-mp[sum]); // If range of length is greater than previous update the length value.
            }else{
                mp[sum]=i; //Insert sum as a key into map and index as a value when that sum is not present in map.
            }
        }

        return length;

    }
    
    
};