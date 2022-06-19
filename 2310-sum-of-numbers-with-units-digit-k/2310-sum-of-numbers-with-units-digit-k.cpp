class Solution {
public:
    
//     Assume the size of the set is n, and the numbers in the set are A1, A2,..., An

//     A1 + A2 + ... + An = sum
//     All numbers must have k as the unit digit
//     So A1 + A2 + ... + An = n*k + 10*(a1 + a2 + .. + an) = sum

//     Which (a1 + a2 + .. + an) can be any number.

//     For example:
//     sum = 58, k = 9 => we have n*k = 2*9 = 18, and 10*(a1 + a2) = 58 - 18 = 40. So a1 + a2 = 4

//     Just find the minimum number satisfying the condition (n*k)%10==sum%10
        
    int minimumNumbers(int num, int k) {
        
        if(num==0)
            return 0;
        
        if(num%10==k)
            return 1;
        
        for(int i=1; i<=10; i++){
            if((i*k)%10==num%10 && i*k<=num) return i;
        }
        
        
        return -1;
    }
};