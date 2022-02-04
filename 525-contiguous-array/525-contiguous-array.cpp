class Solution {
public:
    int findMaxLength(vector<int>& nums) {
    /* if(nums.size()==0 || nums.size()==1)
         return 0;
    if((nums[0]==0 && nums[1]==1) || (nums[0]==1 && nums[1]==0) && nums.size()==2)
        return 2;
        */
        
        
    nums.insert(nums.begin(), 0);
    
    for(int i=1; i<nums.size(); i++){
        if(nums[i]==0)
            nums[i]=-1;
    }
    unordered_map<int, int>mp;
    int length=0;
    int sum=1;
    mp[sum]=0;
    for(int i=1; i<nums.size(); i++){
        sum+=nums[i];
        //cout<<sum<<endl<<endl;
        if(mp.find(sum)!=mp.end()){
            length=max(length, i-mp[sum]);
        }else{
            mp[sum]=i;
        }
    }
    
    return length;
        
    }
    
    
};