class Solution {
public:
    string arrangeWords(string sentence) {
        map<int,vector<string>> mp;
        sentence[0] = tolower(sentence[0]);

        sentence.push_back(' ');
        string str = "", res = "";
        for(char ch : sentence){
            if(ch!=' ')str.push_back(ch);
            else{
                mp[(int)str.size()].push_back(str);
                str = "";
            }
        }
        
        for(auto x : mp){
            for(auto y : x.second){
                res+=(y+' ');                
            }
        }
        
        res.pop_back();
        res[0] = toupper(res[0]);
        return res;
    }
};