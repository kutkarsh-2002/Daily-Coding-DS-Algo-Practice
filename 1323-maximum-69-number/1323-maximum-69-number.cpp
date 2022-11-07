class Solution {
public:
    int maximum69Number (int num) {
        
        string s=to_string(num);
        
        bool flag=false;
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='6' && flag==false){
                s[i]='9';
                flag=true;
            }
        }
        
        return stoi(s);
    }
};