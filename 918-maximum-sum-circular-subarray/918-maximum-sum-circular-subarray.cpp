class Solution {
public:
    //int maxSubarraySumCircular(vector<int>& nums) {
        /*int mx=INT_MIN;
        int j=0;
        for(int i=0; i<nums.size(); i++){
            j=i+1;
            if(i==nums.size()-1){
                j=0;
            }
            mx=max(mx, nums[i]);
            int currsum=0;
            currsum+=nums[i];
            while(i!=j){
                currsum+=nums[j];
                j++;
                if(j==nums.size()){
                    j=j%(nums.size());
                }
                mx=max(mx, currsum);
            }
            
            
        }
        return mx;*/
        
   // }
        
    int normalMaximum(vector<int> &nums)//kadane's algorithm
        {
            int res=nums[0];
            int maxending=nums[0];

            for(int i=1;i<nums.size();i++)
            {
                maxending=max(maxending+nums[i],nums[i]);
                res=max(res,maxending);
            }
            return res;
        }
    int maxSubarraySumCircular(vector<int>& nums) 
        {
            int max_normal=normalMaximum(nums);

            if(max_normal<0)//when all elements are -ve
                return max_normal;

            int sum=0;
            for(int i=0;i<nums.size();i++)
            {
                sum+=nums[i];//current array sum
                nums[i]=-nums[i];//inverting the current array
            }
            int maxcircular=sum+normalMaximum(nums);//sum of given array + maximum subarray sum of inverted subarray
            return max(max_normal,maxcircular);
        }
    
};