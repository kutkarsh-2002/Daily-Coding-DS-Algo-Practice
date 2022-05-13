class Solution {
public:
    
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        
        vector<long long>res;
        int k=intLength;
        long long Cpalk;
        
        //count total number of possible palindrome of kth digits
        long long p=(k&1)?((k+1)/2-1):(k/2-1);
        Cpalk=(long long)pow(10LL, p)*9;
        
        
        for(int i=0; i<queries.size(); i++){
            
            //If value of queries is greater than possible number of palindrome of kth digit push_back -1
            
            if(Cpalk<queries[i]){
                res.push_back(-1);
            }
            else{
                
                int n=queries[i];
                
                // We can easily write the above sequence for nth
//                 palindrome as: (n-1) + 1000
//                 For k digit number, we can generalize above formula as:

//                 If k is odd
//                 => num = (n-1) + 10k/2
//                 else 
//                 => num = (n-1) + 10k/2 - 1 

//                 Now rest half digits can be expanded by just 
//                 printing the value of num in reverse order. 
//                 But before this if k is odd then we have to truncate 
//                 the last digit of a value num 
                    
                    
                long long temp = (k & 1) ? (k / 2) : (k/2 - 1);
                long long num= (long long)pow(10LL, temp);
                num += n - 1;
                
                
                string ans="";
                
                if(k&1){
                    if(num<10){
                        res.push_back(num);
                        continue;
                    }
                    
                    int t=num%10;
                    num=num/10;
                    
                    ans+=to_string(num);
                    string temp=ans;
                    ans+=to_string(t);
                    
                    reverse(temp.begin(), temp.end());
                    ans+=temp;
                    
                    res.push_back(stoll(ans));
                    
                }else{
                    ans+=to_string(num);
                    string temp=ans;
                    reverse(temp.begin(), temp.end());
                    ans+=temp;
                    
                    res.push_back(stoll(ans));
                    
                }
                
            }
        }
        
        return res;
    }
};