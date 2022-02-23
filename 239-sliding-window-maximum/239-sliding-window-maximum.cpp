class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n=arr.size();
        deque<int>dq;
        vector<int>res;
        int i=0, j=0;
        
        while(i<=n-k && j<n)
        {
            
            if(dq.size()==0){
                dq.push_back(arr[j]);
            }
            else if(dq.back()>arr[j]){
                dq.push_back(arr[j]);
            }
            else{
                
                while(!dq.empty() && dq.back()<arr[j]){
                    dq.pop_back();
                }
                
                dq.push_back(arr[j]);
            }
            
            if(j-i+1==k){
                
                res.push_back(dq.front());
                
                if(arr[i]==dq.front()){
                    dq.pop_front();
                }
                
                i++;
            }
            
            j++;
        }
        
        return res;
    }
};