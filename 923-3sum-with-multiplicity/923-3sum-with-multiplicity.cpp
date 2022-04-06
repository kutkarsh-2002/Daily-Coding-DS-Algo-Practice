class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int MOD=1e9+7;
        unordered_map<int,int> um;
        long ans=0;
        int n=arr.size();
        
        //Storing frequency in hashtable
        for(int i=0;i<n;i++){
            um[arr[i]]++;
        }
        
        //Sorting as order won't matter (Think deeply)
        sort(arr.begin(),arr.end());
        
        int i=0;
        
        while(i<n){ //Will increment i inside loop
            int low=i+1,high=n-1;
            
            while(low<high){
                
                //Three elements are arr[i] , arr[low] and arr[high]
                int sum=arr[i]+arr[low]+arr[high];
                
                if(sum==target){
                   
                    //Case 1 : All three elements are same
                    if(arr[i]==arr[low] && arr[i]==arr[high]){
                        long count=um[arr[i]];
                        count=(count)*(count-1)*(count-2)/6;
                        ans=(ans+count)%MOD;
                    }
                    
                    //Case 2 : Any two elements are same 
                    else if(arr[i]==arr[low]){
                        long count=um[arr[i]];
                        count=((count)*(count-1))%MOD/2;
                        count=(count*um[arr[high]])%MOD;
                        ans=(ans+count)%MOD;
                    }
                    else if(arr[i]==arr[high]){
                        long count=um[arr[i]];
                        count=((count)*(count-1))%MOD/2;
                        count=(count*um[arr[low]])%MOD;
                        ans=(ans+count)%MOD;
                    }
                    else if(arr[low]==arr[high]){
                        long count=um[arr[low]];
                        count=((count)*(count-1))%MOD/2;
                        count=(count*um[arr[i]])%MOD;
                        ans=(ans+count)%MOD;
                    }
                    
                    //Case 3: All elements are unique
                    else{
                        long count=((um[arr[i]]*um[arr[low]])%MOD * um[arr[high]])%MOD;
                        ans=(ans+count)%MOD;
                    }
                    
                    //Incrementing low in tricky way to avoid duplication
                    low=low+1;
                    while(low<high && arr[low]==arr[low-1]){
                        low++;
                    }
                }
                else if(sum<target){
                    low++;
                }
                else{
                    high--;
                }
            }
			
            int j=i+1;           //Increment i accordingly
            while(j<n && arr[j]==arr[i]){
                j++;
            }
            
            i=j;
        }
        return ans;
    }
};