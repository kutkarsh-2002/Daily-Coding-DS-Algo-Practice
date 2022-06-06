class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string , int>mp;
        vector<string>ans;
        for(int i=0; i<list1.size(); i++){
            mp.insert({list1[i], i});
        }
        int mi=INT_MAX;
        for(int i=0; i<list2.size(); i++){
            if(mp.find(list2[i])!=mp.end()){
                int x= mp[list2[i]]+i;
                if(x<mi){
                    if(!ans.empty()){
                        ans.clear();
                        ans.push_back(list2[i]);
                        mi=x;
                    }else{
                        ans.push_back(list2[i]);
                        mi=x;
                    }
                }
                else if(x==mi){
                    ans.push_back(list2[i]);
                    mi=x;
                }
                
            }
        }
        
        return ans;
    }
};