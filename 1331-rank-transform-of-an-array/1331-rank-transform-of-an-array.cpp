class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
       
		if(arr.size() == 0){
			return {};
		}
        unordered_map<int, int>mp;
        vector<int>temp;
        vector<int>res;
        for(int i=0; i<arr.size(); i++){
            temp.push_back(arr[i]);
        }
        sort(temp.begin(), temp.end());
        vector<int>v;
        
        mp[temp[0]]=1;
        for(int i=1; i<temp.size(); i++){
            if(temp[i-1]==temp[i])
                mp[temp[i]]= mp[temp[i-1]];
            else
                mp[temp[i]]=mp[temp[i-1]]+1;
        }
        
        for(int i=0; i<arr.size(); i++){
            res.push_back(mp[arr[i]]);
        }
        
        return res;
        
        
        
    }
};