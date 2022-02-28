class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size()==0){
            return {};
        }
        else if(nums.size()==1){
            return {to_string(nums[0])};
        }
        vector<string>ans;
        int j=0, count=1;
        string temp="";
        temp+=to_string(nums[j]);
            
        for(int i=1; i<nums.size(); i++){
            
            if(nums[i-1]+1!=nums[i]){
                if(count>1){
                    temp+="->";
                    temp+=to_string(nums[i-1]);
                }
                ans.push_back(temp);
                temp="";
                j=i;
                temp+=to_string(nums[i]);
                count=1;
            
            }else{
                count++;
            }
            
            
            
        }
        if(count>1){
            ans.push_back(temp+"->"+to_string(nums[nums.size()-1]));
        }else{
            ans.push_back(temp);
        }
        
        return ans;
    }
};