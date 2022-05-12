class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        long long ways=0;
        
        /*if(cost1>total && cost2>total)
            return 1;
        
        else if(cost1>total && cost2<total){
            ways+=total/cost2;
            ways+=1;
        }
        else if(cost1<total && cost2>total){
            ways+=total/cost2;
            ways+=1;
        }
        else{
            int n=total/cost1;
            
            while(n>=0){
                int x=n*cost1;
                if(total-x>=cost2){
                    ways+=(total-x)/cost2;
                }
                ways+=1;
                n--;
            }
        }
        
        return ways;*/
        
        for(int count=0; count*cost1<=total; count++){
            ways+=(total-count*cost1)/cost2+1;
        }
        
        return ways;
    }
};