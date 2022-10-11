class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        
//         unordered_map<int, int>mp;
//         mp.insert({logs[0][0], logs[0][1]});
        
//         for(int i=1; i<logs.size(); i++){
//             if(mp.find(logs[i][0])==mp.end()){
//                 mp[logs[i][0]]=logs[i][1]-logs[i-1][1];
//             }
//             else{
//                 mp[logs[i][0]]=logs[i][1]-logs[i-1][1];
//             }
            
//         }
        
        
//         int id=-1;
//         int maxhr=0;
        
//         // for(auto x: mp){
//         //     cout<<x.first<< " "<<x.second<<endl;
//         // }
        
//         for(auto x:mp){
//             if(maxhr<x.second){
//                 maxhr=x.second;
//                 id=x.first;
//             }
//             else if(maxhr==x.second && x.first<id){
//                 id=x.first;
//             }
//         }
        
//         return id;
        
        int id=logs[0][0], ans=logs[0][1];
        
        for(int i=1; i<logs.size(); i++){
            if(logs[i][1]-logs[i-1][1]>ans){
                ans=logs[i][1]-logs[i-1][1];
                id=logs[i][0];
            }
            else if(logs[i][1]-logs[i-1][1]==ans && id>logs[i][0]){
                id=logs[i][0];
            }
        }
        
        return id;
        
    }
};