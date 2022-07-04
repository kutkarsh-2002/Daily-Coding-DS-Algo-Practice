class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        long long ans=0;
        
        for(int i=0; i<op.size(); i++){
            string temp=op[i];
            if(temp[0]=='X'){
                if(temp[1]=='+'){
                    ans+=1;
                }else{
                    ans-=1;
                }
            }else{
                if(temp[0]=='+'){
                    ans+=1;
                }else{
                    ans-=1;
                }
            }
        }
        
        return ans;
    }
};