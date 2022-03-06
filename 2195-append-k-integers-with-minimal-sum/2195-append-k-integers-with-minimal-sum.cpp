class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        
        long long sum=0;
        
        sort(nums.begin(), nums.end());
        
        long long n=nums[0]-1;
        
        if(n>0 && k>n){
            long long tempSum=0;
            if(n%2==0){
                  tempSum=n/2;
                  tempSum*=(2+(n-1));
              }else{
                  tempSum=(2+(n-1))/2;
                  tempSum*=n;
              }
            
            sum+=tempSum;
            k=k-n;
        }else if(n>0 && k<=n){
            long long tempSum=0;
            if(k%2==0){
                  tempSum=k/2;
                  tempSum*=(2+(k-1));
              }else{
                  tempSum=(2+(k-1))/2;
                  tempSum*=k;
              }
            return tempSum;
        }
        
        //cout<<sum<<endl;
        
        for(long long i=0; i<nums.size()-1 && k>0; i++){
            
            long long n=(nums[i+1]-nums[i])+1;
            n=n-2;
            if(n<0)
                continue;
            
            long long tempSum = 0;
            
            if(k<=n){
              
              if(k%2==0){
                  tempSum=k/2;
                  tempSum*=(2*(nums[i]+1)+(k-1));
              }else{
                  tempSum=(2*(nums[i]+1)+(k-1))/2;
                  tempSum*=k;
              }
              
              sum+=tempSum;
              return sum;
            }else{
                if(n%2==0){
                  tempSum=n/2;
                  tempSum*=(2*(nums[i]+1)+(n-1));
              }else{
                  tempSum=(2*(nums[i]+1)+(n-1))/2;
                  tempSum*=n;
              }
                
                k=k-n;
                sum+=tempSum;
                
            }
           
        }
        
        if(k>0){
            long long tempSum=0;
            if(k%2==0){
                  tempSum=k/2;
                  tempSum*=(2*(nums[nums.size()-1]+1)+(k-1));
              }else{
                  tempSum=(2*(nums[nums.size()-1]+1)+(k-1))/2;
                  tempSum*=k;
              }
              
              sum+=tempSum;
              cout<<tempSum<<endl;
        }
        
        
        return sum;
    }
};