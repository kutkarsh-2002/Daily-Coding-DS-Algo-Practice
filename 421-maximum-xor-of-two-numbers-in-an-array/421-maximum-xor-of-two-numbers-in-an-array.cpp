class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        /*if(nums.size()==1 || nums.size()==0)
            return 0;
        int mx=INT_MIN;
        for(int i=0; i<nums.size()-1; i++){
            
            for(int j=i; j<nums.size(); j++){
                
                mx=max(mx, nums[i]^nums[j]);
            }
        }
        
        return mx;*/
        
        int n=nums.size();
        
        if(n==0 || n==1){
            return 0;
        }
        
        int mask=0, result=0;
        
        
        for(int i=30; i>=0; i--){
            
            mask=mask | 1<<i;
            unordered_set<int>st;
            
            for(int i=0; i<nums.size(); i++){
                st.insert(mask & nums[i]);
            }
            
            int candidate=result | 1<<i;
            
            for(auto it=st.begin(); it!=st.end(); it++){
                if(st.count(candidate^*it)){
                    
                    result=candidate;
                    break;
                }
            }
            
        }
        
        return result;
    }
};