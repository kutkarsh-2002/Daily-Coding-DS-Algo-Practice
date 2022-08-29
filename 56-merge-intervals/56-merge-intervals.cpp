class Solution {

public:
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.empty()){
            return intervals;
        }
        else if(intervals.size()==1){
            return intervals;
        }
        
//         sort(intervals.begin(), intervals.end());
        
//         vector<vector<int>>mat;
        
//         int p1=intervals[0][0];
//         int p2=intervals[0][1];
//         for(int i=1; i<intervals.size(); i++){
            
//             if(p2>=intervals[i][0]){
//                 p2=max(p2,intervals[i][1]);
//             }else{
//                 vector<int>v;
//                 v.push_back(p1);
//                 v.push_back(p2);
//                 mat.push_back(v);
                
//                 p1=intervals[i][0];
//                 p2=intervals[i][1];
//             }
//         }
        
//         vector<int>v;
//         v.push_back(p1);
//         v.push_back(p2);
//         mat.push_back(v);
        
//         return mat;
        
        stack<pair<int, int>>st;
        sort(intervals.begin(), intervals.end());
        
        st.push({intervals[0][0], intervals[0][1]});
        
        for(int i=1; i<intervals.size(); i++){
            auto x=st.top();
            if(x.second>=intervals[i][1]){
                continue;
            }
            else if(x.second>=intervals[i][0]){
                st.pop();
                st.push({x.first, intervals[i][1]});
            }
            else{
             st.push({intervals[i][0], intervals[i][1]});   
            }
        }
        
        vector<vector<int>>ans;
        
        while(!st.empty()){
            ans.push_back({st.top().first, st.top().second});
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};