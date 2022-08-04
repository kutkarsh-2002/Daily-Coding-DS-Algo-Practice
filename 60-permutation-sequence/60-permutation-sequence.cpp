class Solution {
public:
    //Recursive Approach
//     void findingPermut(string &s, vector<string>&res, int i){
        
//         if(i>=s.size()){
//             res.push_back(s);
//             return;
//         }
        
//         for(int j=i; j<s.size(); j++){
//             swap(s[i], s[j]);
//             findingPermut(s, res, i+1);
//             swap(s[i], s[j]);
//         }
//     }
    
//     string getPermutation(int n, int k) {
        
//         string s="";
//         vector<string>res;
        
//         for(int i=1; i<=n; i++){
//             s+=to_string(i);
//         }
        
//         findingPermut(s,res,0);
        
//         sort(res.begin(), res.end());
        
//         return res[k-1];
//     }
    
    
    /**********Mathematical Approach****************/
    
    string getPermutation(int n, int k){
        int fact=1;
        vector<int>num;
        string ans="";
        
        for(int i=1; i<n; i++){
            fact=fact*i;
            num.push_back(i);
        }
        
        num.push_back(n);
        //for 0 based indexing
        k=k-1;
        while(true){
           // this will take us to that range among permutations of n .We could find the first element among the remaining elements of vector.
            ans+=to_string(num[k/fact]);
            num.erase(num.begin()+k/fact);
            if(num.size()==0)
                break;
            //updated value of k;
            k=k%fact;
            fact=fact/num.size();
        }
        
        return ans;
    }
};