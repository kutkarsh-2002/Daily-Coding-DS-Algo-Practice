class Solution {
public:
    /*bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        if(n==0){
            return true;
        }
        int l=0;
        while(l<flowerbed.size()-1 && n>0){
            if(flowerbed[l]==0 && flowerbed[l+1]==0){
                flowerbed[l]=1;
                n--;
            }
            
            l+=2;
        }
        if(l==flowerbed.size()-1){
            if(flowerbed[l]==0 && flowerbed[l-1]==0){
                n--;
            }
            
        }
        if(n>0){
            return false;
        }
        
        return true;
    }*/
    
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for (int i = 0; i < size(flowerbed); ++i) {
            if (flowerbed[i] == 1) continue;
            if ((i == 0 || flowerbed[i - 1] == 0) && (i == size(flowerbed) - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1; --n;
            }
        }
        return n <= 0;
    }
};