class Solution {
public:
    string arrangeWords(string sentence) {
        map<int,vector<string>> m;
        sentence[0] = tolower(sentence[0]);

        sentence.push_back(' ');
        string str = "", ans = "";
        for(char ch : sentence){
            if(ch!=' ')str.push_back(ch);
            else{
                m[(int)str.size()].push_back(str);
                str = "";
            }
        }
        for(auto x : m){
            for(auto y : x.second){
                ans+=(y+' ');                
            }
        }
        ans.pop_back();
        ans[0] = toupper(ans[0]);
        return ans;
    }
};