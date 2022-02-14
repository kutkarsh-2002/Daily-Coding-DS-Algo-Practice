class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1, -1};
        }
        
        if(nums.size()==1 && nums[0]==target)
        {
            return {0, 0};
        }
        
        vector<int>v;
        bool flag=true;
        int mxInd=INT_MIN;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==target && flag==true)
            {
                 v.push_back(i);
                 flag=false;
            }
            else if(nums[i]==target)
                mxInd=max(mxInd, i);
        }
        if(mxInd!=INT_MIN)
            v.push_back(mxInd);
        
        if(v.size()==0)
        {
            return {-1, -1};
        }else if(v.size()==1)
            v.push_back(v[v.size()-1]);
        
        return v;
        
    }
};