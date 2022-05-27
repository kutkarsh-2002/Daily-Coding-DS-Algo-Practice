class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        if(nums.size()<=2){
            return nums;
        }
        
        vector<int>ve, vo;
        
        for(int i=0; i<nums.size(); i++){
            if(i%2==0){
                ve.push_back(nums[i]);
            }else{
                vo.push_back(nums[i]);
            }
        }
        
        sort(ve.begin(), ve.end());
        sort(vo.begin(), vo.end(), greater<int>());
        
        int j=0, k=0;
        
        for(int i=0; i<nums.size() && j<ve.size() && k<vo.size(); i++){
            if(i%2==0){
                nums[i]=ve[j];
                j++;
            }else{
                nums[i]=vo[k];
                k++;
            }
        }
        
        if(j<ve.size()){
            nums[nums.size()-1]=ve[j];
            j++;
        }else{
             nums[nums.size()-1]=vo[k];
             k++;
        }
        
        return nums;
    }
};