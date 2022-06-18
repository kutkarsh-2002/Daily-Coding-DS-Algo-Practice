class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>res;
        long long suml=0, sumr=0;
        int j=0, i=0;
        
        for(j=1; j<=k && j<nums.size(); j++){
            sumr+=nums[j];
        }
        
        j=j-1;
        
        for(i=0; i<nums.size()-k && j<nums.size(); i++){
            suml+=nums[i];
            if(i!=0){
                sumr-=nums[i];
            }
            
            if(i-k<0 || i+k>=n)
                res.push_back(-1);
            else{
                res.push_back((suml+sumr)/(2*k+1));
                suml-=nums[i-k];
            }
            
            j++;
            if(j<nums.size()){
                sumr+=nums[j];
            }
            
            
            
        }
        
        if(i+k<nums.size())
        {
            res.push_back(nums[i]);
            i++;
        }
        
        while(i<nums.size()){
            res.push_back(-1);
            i++;
        }
        
        return res;
    }
};