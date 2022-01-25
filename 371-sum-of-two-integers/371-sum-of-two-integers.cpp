class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            unsigned carry=a&b; //finding carry
            a=a^b;    //performing sum
            b=carry<<1; //shifting carry by 1 to add it to next bits
        }
        
        return a;
    }
};