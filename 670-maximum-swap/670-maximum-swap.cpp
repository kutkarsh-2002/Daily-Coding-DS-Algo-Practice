class Solution {
public:
    int maximumSwap(int nums) {
        
        string res=to_string(nums);
        
        int ind=0, k=1;
        
        for(int i=0; i<res.size() && k>0; i++)
        {
            int mx=INT_MIN;
            for(int j=i+1; j<res.size() && k>0; j++)
            {
                if(mx<=res[j]-'0')
                {
                    mx=res[j]-'0';
                    ind=j;
                } 
            }
            
            if(mx>res[i]-'0')
            {
                swap(res[i], res[ind]);
                k--;
            }
            else
            {
                ind=0;
                mx=INT_MIN;
            }   
        }
        
        return stoi(res);
        
    }
};