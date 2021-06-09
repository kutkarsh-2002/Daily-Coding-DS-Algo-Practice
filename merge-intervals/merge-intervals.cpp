class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size()==0)
        return intervals;
        sort(intervals.begin(), intervals.end());
        vector<int> temp=intervals[0];
        vector<vector<int>> merged;
        for(auto it: intervals){
        if(it[0]<=temp[1])
        temp[1]=max(it[1],temp[1]);
        else{
        merged.push_back(temp);
        temp=it;
        }
        }
        merged.push_back(temp);
        return merged;
        }

        
};