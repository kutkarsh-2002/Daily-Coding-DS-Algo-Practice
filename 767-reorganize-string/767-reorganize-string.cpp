class Solution {
public:
    
    string reorganizeString(string s) {
        
        unordered_map<char, int>mp;
        priority_queue<pair<int, char>>pq;
        string res="";
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
        }
        
        for(auto x:mp){
            pq.push(make_pair(x.second, x.first));
        }
        
        while(pq.size()>1){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            res+=top1.second;
            res+=top2.second;
            top1.first=top1.first-1;
            top2.first=top2.first-1;
            
            if(top1.first>0){
                pq.push(top1);
            }
            
            if(top2.first>0){
                pq.push(top2);
            }
            
        }
        
        if(!pq.empty()){
            if(pq.top().first>1)
                return "";
            else
                res+=pq.top().second;
        }
        
        return res;
    }
};