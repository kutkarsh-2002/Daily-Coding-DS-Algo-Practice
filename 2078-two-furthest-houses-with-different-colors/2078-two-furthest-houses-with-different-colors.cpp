class Solution {
public:
    int maxDistance(vector<int>& colors) {
        
        int i, first = colors[0], sz = colors.size();
        int j, last = colors[sz - 1];
        for(i = sz - 1 ; i >= 0 ; i--) if(colors[i] != first) break;
        for(j = 0 ; j < sz ; j++) if(colors[j] != last) break;
        return max(i, sz-1-j);
    }
};