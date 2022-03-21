class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        /*multimap<string, int>mp;
        int count=0;
        
        for(int i=0; i<nums.size(); i++){
            mp.insert({nums[i], i});
        }
        
        for(auto x: mp){
            cout<<x.first<<" "<<x.second<<endl;
        }
        cout<<endl;
        
        for(int i=0; i<nums.size(); i++){
            string temp=target;
            int pos=target.find(nums[i]);
            
            if(pos!=string::npos){
                target.erase(pos, nums[i].length());
                
                if(mp.find(target)!=mp.end() && mp.find(target)->second!=i){
                    count++;
                    cout<<i<<" "<<mp.find(target)->second<<endl;
                }
            }
            
            target=temp;
        }
        
        return count;*/
        
        int count=0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[i]+nums[j]==target && i!=j){
                    count++;
                }
            }
        }
        
        return count;
    }
};