class Solution {
    
public:
    
    static bool comp(string &s1, string &s2){
        return s1.size()<s2.size();
    }
    
    bool compare(string & curr, string & pre){
        if(curr.size()!=pre.size()+1) return false;
        
        int i=0, j=0;
        while(i<curr.size()){
            if(curr[i]==pre[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
         
            if(i==curr.size() && j==pre.size()) return true;
            
            return false;
    }
    
    int longestStrChain(vector<string>& nums) {
        int n=nums.size();
        //sort the string according to their length because this is subset which can have any order.
        sort(nums.begin(), nums.end(), comp);
        vector<int>dp(n, 1), hash(n);
        int maxi=1;
        int lastInd=0;
        
        for(int i=0; i<n; i++){
            hash[i]=i;
            for(int prev=0; prev<i; prev++){
                
                if(compare(nums[i],nums[prev]) && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastInd=i; 
            }
        }
        vector<string>temp;
        
        while(hash[lastInd]!=lastInd){
            temp.push_back(nums[lastInd]);
            lastInd=hash[lastInd];
        }
        
        temp.push_back(nums[lastInd]);
        reverse(temp.begin(), temp.end());
        
        for(auto x: temp){
            cout<<x<<" ";
        }
        
        return maxi;
    }
};