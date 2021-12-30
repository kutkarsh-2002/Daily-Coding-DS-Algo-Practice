class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0,curr_gas=0, prev_gas=0;
       
       for(int i=0; i<gas.size(); i++){
           curr_gas+=gas[i]-cost[i];
           
           if(curr_gas<0){
               start=i+1;
               prev_gas+=curr_gas;
               curr_gas=0;
               
           }
           
       }
       
       return (curr_gas+prev_gas>=0)?start:-1;
    }
};