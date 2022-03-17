class Solution {
public:
    
    int largestRectangleArea(vector<int>& heights) {
        
        stack<int>s1;
        stack<int>s2;
        vector<int>ns;
        vector<int>ps;
        
        int n=heights.size();
        //next smaller element
        for(int i=heights.size()-1;i>=0; i--){
            while(s1.empty()==false && heights[i]<=heights[s1.top()]){
                s1.pop();
            }
            int val=(s1.empty())?n:s1.top();
            ns.push_back(val);
            s1.push(i);
        }
        reverse(ns.begin(), ns.end());
        
        //previous smaller element
        for(int i=0; i<heights.size(); i++){
            while(s2.empty()==false && heights[i]<=heights[s2.top()]){
                s2.pop();
            }
            
            int val=(s2.empty())?-1:s2.top();
            ps.push_back(val);
            s2.push(i);
        }
        int res=0, curr;
        
        for(int i=0; i<heights.size(); i++){
            curr=heights[i];
            curr+=(i-ps[i]-1)*heights[i];
            curr+=(ns[i]-i-1)*heights[i];
            res=max(curr, res);
        }
        
        return res;
        
        
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int maxRect=INT_MIN;
        vector<int>v(matrix[0].size(), 0);
        
        for(int i=0; i<matrix.size(); i++){
            
            for(int j=0; j<matrix[0].size(); j++){
                if(matrix[i][j]=='1'){
                    v[j]+=matrix[i][j]-'0';
                }
                else{
                    v[j]=0;
                }
            }
            
            maxRect=max(maxRect, largestRectangleArea(v));
            
        }
    
        return maxRect;
    }
};