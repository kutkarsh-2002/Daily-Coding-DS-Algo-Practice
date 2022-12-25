class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int>res;
        
        for(int i=0; i<queries.size(); i++){
            int sum=0;
            int size=0;
            
            for(int j=0; j<nums.size(); j++){
                sum+=nums[j];
                if(sum>queries[i]){
                    break;
                }
                else if(sum>=queries[i]){
                    size++;
                    break;
                }
                else{
                    size++;
                }
            }
            
            res.push_back(size);
        }
        
        return res;
    }
};