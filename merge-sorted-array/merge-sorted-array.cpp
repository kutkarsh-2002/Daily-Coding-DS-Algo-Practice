class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        /*int i=0, j=0;
        
        while(i<m && j<n){
            
            if(nums1[i]<nums2[j] && i<m && nums1[i]==0){
                i++;
            }
            
           else if(nums1[i]<nums2[j] && nums1[i]==0){
                nums1[i]=nums2[j];
                i++;
                j++;
                
            }
            
            else if(nums1[i]<=nums2[j]){
                i++;
            }
            else if(nums1[i]>nums2[j] || (nums1[i]==0 && nums2[j]<0)){
                int temp=nums1[i];
                nums1[i]=nums2[j];
                nums2[j]=temp;
                i++;
                sort(nums2.begin(), nums2.end());
            }
        }*/
        
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k]=nums1[i];
                i--;
                k--;
            }
            else
            {
                nums1[k]=nums2[j];
                j--;
                k--;
            }
        }
        while(i>=0)
            nums1[k--]=nums1[i--];
        while(j>=0)
            nums1[k--]=nums2[j--];
    }
};