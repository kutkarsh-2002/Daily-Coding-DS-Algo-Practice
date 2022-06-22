class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int>pq;
        
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        int ans=INT_MIN, mx=INT_MIN, k=3;
        
        while(!pq.empty() && k>0){
            if(mx==INT_MIN){
                mx=max(mx, pq.top());
            }
            
            if(ans!=pq.top()){
                k--;
            }
            
            ans=pq.top();
            pq.pop();
            
        }
        
        //cout<<k<<endl;
        return (k==0)?ans:mx;
        
    }
};