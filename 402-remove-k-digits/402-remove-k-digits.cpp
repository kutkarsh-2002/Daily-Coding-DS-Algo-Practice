class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size()==0)
            return "0";
        
        if(k==0)
            return num;
        
        stack<char>s;
        string res="";
        
        s.push(num[0]);
        
        for(int i=1; i<num.size(); i++){
            
            while(k>0 && !s.empty() && num[i]<s.top()){
                s.pop();
                k--;
            }
            
            s.push(num[i]);
            
            if(num[i]=='0' && s.size()==1)
                s.pop();
            
        }
        
        while(k && !s.empty())
        {
            s.pop();
            k--;
        }
        
        while(!s.empty())
        {
            res.push_back(s.top());
            s.pop();
        }
        
        reverse(res.begin(), res.end());
        
        return (res.size()==0)?"0":res;
        
    }
};