class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_map<char, string>mp;
        
        mp['a']=".-"; mp['b']="-..."; mp['c']="-.-."; mp['d']="-.."; mp['e']=".";  mp['f']="..-.", mp['g']="--."; mp['h']="....";  mp['i']="..";  mp['j']=".---";  mp['k']="-.-"; mp['l']=".-..";  mp['m']="--"; mp['n']="-.";  mp['o']="---"; mp['p']=".--.";  mp['q']="--.-";  mp['r']=".-.";  mp['s']="...";  mp['t']="-";  mp['u']="..-";  mp['v']="...-"; mp['w']=".--"; mp['x']="-..-";  mp['y']="-.--"; mp['z']="--..";
        
        int count=0;
        unordered_map<string, int>m;
        
        for(int i=0; i<words.size(); i++){
            string temp="";
            string t=words[i];
            for(int j=0; j<t.size(); j++){
                temp+=mp[t[j]];
            }
            
            if(m.find(temp)!=m.end()){
                m[temp]++;
            }else{
                m.insert({temp, 1});
            }
            //cout<<temp<<endl;
        }
        
        for(auto x:m){
            count++;
        }
        
        return count;
    }
};