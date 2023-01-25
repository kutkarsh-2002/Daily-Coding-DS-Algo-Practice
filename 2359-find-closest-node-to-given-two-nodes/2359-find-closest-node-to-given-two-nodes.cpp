class Solution {
public:
    
//     void dfs(int node, vector<int>& edges, unordered_map<int, int>&mp, int dis){
//         if()
//     }
//     int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
//         unordered_map<int, int>m1;
//         unordered_map<int, int>m2;
        
//         dfs(node1, edges, mp1, 0);
//     }
    
    int closestMeetingNode(vector<int>& e, int node1, int node2) {
    int res = -1, min_dist = INT_MAX;
    vector<int> m1(e.size(), -1), m2(e.size(), -1);
    for (int i = node1, dist = 0; i != -1 && m1[i] == -1; i = e[i])
        m1[i] = dist++;
    for (int i = node2, dist = 0; i != -1 && m2[i] == -1; i = e[i]) {
        m2[i] = dist++;
        if (m1[i] >= 0 && max(m1[i], m2[i]) <= min_dist) {
            res = max(m1[i], m2[i]) == min_dist ? min(i, res) : i;
            min_dist = max(m1[i], m2[i]);
        }
    }
    return res;
}
};