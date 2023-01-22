class Solution {
public:
    
    void Partition(int i, string& s, vector<string>&v, vector<vector<string>>&res)
    {
        if(i==s.size()){
            res.push_back(v);
            return ;
        }
        
        for(int j=i; j<s.size(); j++){
            if(isPalin(i, j, s)){
                v.push_back(s.substr(i, j-i+1));
                Partition(j+1, s, v, res);
                v.pop_back();
            }
        }
    }
    
    bool isPalin(int i, int j, string&s){
        while(i<=j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>v;
        
        Partition(0, s, v, res);
        
        return res;
    }
};