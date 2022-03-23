class Solution {
public:
    
    /*int findOp(int startValue, int &target, int &res){
        if(startValue==target || startValue>10^9 || startValue<1){
            return 0;
        }
        
        res+=1+min(findOp(startValue*2, target, res), findOp(startValue-1, target, res));
        
        return res;
    }
    
    int brokenCalc(int startValue, int target) {
        
        if(startValue==target)
            return 0;
        
        int res=0;
        
        return findOp(startValue, target, res);
    
    }*/
    
    int brokenCalc(int startValue, int target) {
        
        int res=0;
        while(target>startValue){
            if(target%2){
                target++;
            }else{
                target/=2;
                
            }
            res++;
        }
        
        return startValue-target+res;
    
    }
    
};