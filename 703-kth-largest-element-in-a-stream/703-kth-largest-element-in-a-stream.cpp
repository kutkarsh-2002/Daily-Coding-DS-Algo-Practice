class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    //vector<int>g;
    int K;
    KthLargest(int k, vector<int>& nums) {
        
        K=k; 
        // for(int i=0; i<nums.size(); i++){
        //     g.push_back(nums[i]);
        // }
        
        for(auto x: nums){
            pq.push(x);
            if(pq.size()>K){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        
//         g.push_back(val);
        
//         sort(g.begin(), g.end(), greater<int>());
//         return g[K-1];
        pq.push(val);
        
        if(pq.size()>K)
            pq.pop();
        
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */