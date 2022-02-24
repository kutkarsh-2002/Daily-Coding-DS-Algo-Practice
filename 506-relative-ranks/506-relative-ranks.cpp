class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string>res;
        priority_queue<int>pq;
        unordered_map<int, int>mp;
        
        for(int i=0; i<score.size(); i++){
            pq.push(score[i]);
        }
        
        int pos=1;
        
        while(!pq.empty()){
            mp.insert({pq.top(), pos});
            pos++;
            pq.pop();
        }
       
        for(int i=0; i<score.size(); i++){
            if(mp[score[i]]==1){
                res.push_back("Gold Medal");
            }
            else if(mp[score[i]]==2)
                res.push_back("Silver Medal");
            else if(mp[score[i]]==3)
                res.push_back("Bronze Medal");
            
            else
                res.push_back(to_string(mp[score[i]]));
        }
        return res;
    }
};