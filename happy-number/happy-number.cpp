class Solution {
public:
    bool isHappy(int n) {
//         long long int sum=0;
//         int temp=n;
        
//             while(sum!=1 && sum<=INT_MAX){
//             while(0<temp<=INT_MAX){
//                 int a=temp%10;
//                 sum=sum+(a*a);
//                 temp/=10;
//             }
//             temp=sum;
//         }
//         return sum==1?true:false;
        
         set<int> s;
    while(s.count(n)==0)
    {
        if(n==1) return true;
        s.insert(n);
        int temp=0;
        while(n)
        {
            temp+= (n%10)*(n%10);
            n/=10;
        }
        n=temp;
    }
    return false;
        
    }
};
