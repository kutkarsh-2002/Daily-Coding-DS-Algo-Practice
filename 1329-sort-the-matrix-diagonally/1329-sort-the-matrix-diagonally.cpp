class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat[0].size(), n=mat.size();
        
        for(int j=m-1; j>=0; j--){
            int i=0; 
            int q=j;
            vector<int>v;
            
            while(i<n && q<m){
                v.push_back(mat[i][q]);
                i++;
                q++;
            }
            
            sort(v.begin(), v.end());
            i=0, q=j;
            int ind=0;
            
            while(i<n && q<m && ind<v.size()){
                mat[i][q]=v[ind];
                i++;
                q++;
                ind++;
            }
            
            
        }
        
        for(int i=1; i<n; i++){
            int p=i;
            int j=0;
            vector<int>v;
            
            while(p<n && j<m){
                v.push_back(mat[p][j]);
                p++;
                j++;
            }
            
            sort(v.begin(), v.end());
            j=0, p=i;
            int ind=0;
            
            while(j<m && p<n && ind<v.size()){
                mat[p][j]=v[ind];
                p++;
                j++;
                ind++;
            }
        }
        
        return mat;
    }
    
    
};