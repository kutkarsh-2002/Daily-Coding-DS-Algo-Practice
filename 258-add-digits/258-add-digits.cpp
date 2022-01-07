class Solution {
    int sumofDigits(int num){
        int sum=0;
        while(num>0){
            int rem=num%10;
            sum+=rem;
            num=num/10;
        }
        return sum;
    }
public:
    int addDigits(int num) {
        
        while(num/10!=0){
            num=sumofDigits(num);
        }
        
        return num;
    }
};