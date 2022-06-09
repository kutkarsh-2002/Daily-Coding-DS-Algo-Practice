class Solution {
public:
    int m=1e9+7;
    
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        
        while(k--){
            int t=pq.top();
            pq.pop();
            t+=1;
            pq.push(t);
        }
        
        long long res=1;
        
        while(!pq.empty()){
            
            res=(res%m*pq.top()%m)%m;
            pq.pop();
        }
        
        return res%m;
    }
};