class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size()>1){
            deque<int>dq;
            
            for(int i=0; i<nums.size(); i++){
            dq.push_back(nums[i]);
         }
            
            nums.clear();
            
           while(k--){
               dq.push_front(dq.back());
               dq.pop_back();
           } 
            
            while(!dq.empty()){
                nums.push_back(dq.front());
                dq.pop_front();
            }
            
        }
    }
};