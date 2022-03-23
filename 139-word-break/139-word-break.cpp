class Solution {
public:
    
    /* Backtracking method */
    
    /*bool wordFind(string s, int pos, unordered_set<string>&st){
        if(pos==s.size())
            return true;
        
        
        for(int i=pos; i<s.size(); i++){
            if(st.find(s.substr(pos, i-pos+1))!=st.end() && wordFind(s, i+1, st)){
                return true;
            }
        }
        
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>st;
        
        for(int i=0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }
//         string temp="";
//         for(int i=0; i<s.size(); i++){
//             temp+=s[i];
//             if(st.find(temp)!=st.end()){
//                 temp="";
//             }
//         }
        
//         if(temp!=""){
//             return false;
//         }
        
//         return true;
        
        return wordFind(s, 0, st);
    }
    
    */
    
    //Memoization method
    
    int dp[305];
    
    int wordFind(string s, int pos, unordered_set<string>&st){
        
        if(pos==s.size())
            return true;
        
        if(dp[pos]!=-1){
            return dp[pos];
        }
        
        for(int i=pos; i<s.size(); i++){
            if(st.find(s.substr(pos, i-pos+1))!=st.end() && wordFind(s, i+1, st)){
                dp[pos]=1;
                return 1;
            }
        }
        
        dp[pos]=0;
        return 0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        memset(dp, -1, sizeof(dp));
        
        for(int i=0; i<wordDict.size(); i++){
            st.insert(wordDict[i]);
        }
        
        return wordFind(s, 0, st);
    }
};