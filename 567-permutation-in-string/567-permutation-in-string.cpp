class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char,int> m;
        for(int j=0; j<s1.length(); j++)
        {
            m[s1[j]]++;
        }
         int count=m.size();//count variable to check when all the 
        //characters present in the map have frequencies zero,which
            //implies that an anagram is found.
        int k=s1.length();//Window size.
        int i=0;
        int j=0;
        while(j<s2.length())
        {
            if(m.find(s2[j]) != m.end())
            {
                m[s2[j]]--;
                if(m[s2[j]]==0)
                    count--;
            }
            if(j-i+1<k)
                j++;
            else if(j-i+1==k)
            {
                if(count==0)
                    return true;
               if(m.find(s2[i])!=m.end())//while sliding the window check if that 
                   //character is present in the map then increase it's frequency
                   //by one as we have decreased the frequency of that character 
                   //when it was first encountered while traversing the window.
                {
                    m[s2[i]]++;
                    if(m[s2[i]]==1)
                        count++;
                }
                i++;
                j++;
            }
        }
        
        return false;
        
    
    }
};