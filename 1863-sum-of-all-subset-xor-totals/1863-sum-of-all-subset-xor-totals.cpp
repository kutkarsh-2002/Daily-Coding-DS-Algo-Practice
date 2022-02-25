class Solution {
public:
    void subsets(vector<int>&nums, int i, int temp, int &res){
        
        if(i>=nums.size()){
            res+=temp;
            return ;
        }
        
        subsets(nums, i+1, temp, res);
        temp=temp^nums[i];
        subsets(nums, i+1, temp, res);
        return ;
        
    }
    int subsetXORSum(vector<int>& nums) {
        
        /*vector<vector<int>>ans;
        
        // finding all subssets of given array
        
        ans.push_back({});
        
        for(int i=0; i<nums.size(); i++){
            
            for(int j=0; j<ans.size(); j++){
                vector<int>temp=ans[j];
                temp.push_back(nums[i]);
                ans.push_back(temp);
            }
        }
        
        
        int res=0;
        
        for(int i=0; i<ans.size(); i++){
            
            if(ans[i].size()==0)
                res+=0;
            else if(ans[i].size()==1)
                res+=ans[i][0];
            else{
                
                int sum=0;
                
                for(int j=0; j<ans[i].size(); j++){
                    sum=sum^ans[i][j];
                }
                
                res+=sum;
            }
        }
        
        return res;*/
        vector<int>v;
        int res=0;
        subsets(nums, 0, 0 , res);
        return res;
    }
};